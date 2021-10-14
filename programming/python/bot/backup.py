import datetime as dt
import os
import os.path
import re
import time
from sys import path
from typing import Literal

import aiohttp
import discord
import pandas as pd
import requests
from bs4 import BeautifulSoup
from dateutil.tz import gettz
from discord.ext import tasks
from pytz import timezone
from redbot.core import commands, config
from redbot.core.config import Config
from redbot.core.utils import chat_formatting as cf
from redbot.core.utils.menus import DEFAULT_CONTROLS, menu
from tabulate import tabulate

from . import res

"""
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
RequestType = Literal["discord_deleted_user", "owner", "user", "user_strict"]
"""


class ClsRoom(commands.Cog):
    """cog to maintain classroom things"""

    def __init__(self, bot):
        self.bot = bot
        self.config = Config.get_conf(
            self,
            identifier=12345,
            force_registration=False,
        )
        self.config.register_user(dept=None, batch=None, dm=False, ctx=None)

        self.ref_time = [dt.time(hr, 30) for hr in [9, 10, 13, 14, 15]]
        self.mapper = {
            "cse3b": [res.cse3b_b1, res.cse3b_b2],
            "cse3c": [res.cse3c_b1, res.cse3c_b2],
            "cse2c": [res.cse2c_b1, res.cse2c_b2],
            "mtech2": [res.mtech2],
            "aids2": [res.aids_b1, res.aids_b2],
            "srm": [res.srm]
        }

        self.title_map = {
            "cse3b": "CSE III-B",
            "cse3c": "CSE III-C",
            "cse2c": "CSE II-C",
            "mtech2": "M.Tech CSE II",
            "aids2": "AIDS II",
            "srm": "SRM"
        }

        # rollnum things
        self.data = pd.read_csv(
            os.path.join(os.path.abspath(__file__ + "/../../"),
                         "clsroom/resource/db.csv")
        )
        self.ai_data = pd.read_csv(
            os.path.join(os.path.abspath(__file__ + "/../../"),
                         "clsroom/resource/ai.csv")
        )
        self.config = Config.get_conf(
            self,
            identifier=12345,
            force_registration=True,
        )
        self.spam_link.start()

    def cog_unload(self):
        self.spam_link.cancel()

    @tasks.loop(seconds=300)
    async def spam_link(self):
        """dm class link to registered users before 5 mins class starts"""
        now = dt.datetime.now(tz=gettz("Asia/Kolkata"))
        t = now.replace(minute=30) - now

        if now.hour in [9, 10, 13, 14, 15] and t.seconds <= 900 and t.seconds > 0:

            v = await self.config.all_users()
            for user in v:
                if v[user]["dm"]:
                    a = await self.link(user)
                    if a:
                        await self.bot.get_user(user).send(embed=a)

    @commands.command(aliases=["sal"])
    @commands.is_owner()
    async def sendalllinks(self, ctx):
        """send all class link to registered users"""
        now = dt.datetime.now(tz=gettz("Asia/Kolkata"))
        v = await self.config.all_users()

        for user in v:
            if v[user]["dm"]:
                await self.bot.get_user(user).send("Due to bot down today, links are sent now")
                for i in [9, 10, 13, 14, 15]:
                    n = now.replace(hour=i, minute=25)

                    a = await self.link(user, None, None, n)
                    if a:
                        await self.bot.get_user(user).send(embed=a)

    @spam_link.before_loop
    async def before_printer(self):
        await self.bot.wait_until_ready()

    @commands.command()
    async def dmlinks(self, ctx, toggle: bool):
        """Set toggle to Send link of the class to join in dm before 5 mins\nuse `[p] dmlinks false` to not spam in your dm"""
        await ctx.tick()
        if toggle:
            usr_msg = await ctx.author.send(
                f"{ctx.author.mention} You have registered to dm links before 5 mins of class starts.\n To stop this service, use `$dmlinks false`"
            )

        async with self.config.user_from_id(ctx.author.id).all() as user_data:
            user_data["dm"] = toggle

    # for sem and internals

    @commands.command(aliases=["ls"])
    @commands.is_owner()
    async def sem_cia(self, ctx):
        embed = discord.Embed(
            title="Exams dates",
            color=discord.Color.red(),
        )
        embed.set_thumbnail(
            url="https://s3.getstickerpack.com/storage/uploads/sticker-pack/zenitsu-special/sticker_3.png?1dce9cfb39803bcc63aa2d3a17211cf1&d=200x200"
        )
        """
        Available year:
        -2nd year
        Command:
        -cia2
        -cia3
        -sem3
        """
        exam_schedule = ""

        for i in res.exams:
            exam_schedule += i
        embed.add_field(
            name="exam schedule :",
            value=exam_schedule,
        )
        await ctx.send(embed=embed)

    # for getting specific class links
    # sugan0tech part
    exams = {
        "cia2",
        "2021-10-11 ",
        "2021-10-13 ",
        "cia3  ",
        "2021-11-22 ",
        "2021-11-24 ",
        "sem",
        "2021-11-25 SEM-LAB",
        "2021-12-06 SEM-EXM"
    }

    @commands.command(aliases=["cl"])
    async def Cls_links(self, ctx):

        embed = discord.Embed(
            title="All meet links",
            description="",
            color=discord.Color.orange(),
        )
        embed.set_thumbnail(
            url="https://cdn.myanimelist.net/images/characters/6/384253.jpg"
        )
        links_lst = ""
        for dept_links in res.cse2c_links:
            links_lst += dept_links + \
                f" : [meet-link]({res.cse2c_links[dept_links]}) \n"

        embs = []

        embed.add_field(
            name="For CSE 2 C",
            value=links_lst,
        )
        embs.append(embed)
        await ctx.send(embed=embed)

    @commands.command(aliases=["con"])
    async def connect(self, ctx, dept, batch: int = None):
        """Connect to your class and batch to get the link instantneously while using [p]link or [p]timetable

        Available departments:
        - aids2
        - cse2c
        - cse3b
        - cse3c
        - mtech2
        Others :
        - srm
        """
        if dept not in self.mapper.keys():
            return await ctx.send(
                "Invalid department. Please choose from:\n"
                + ", ".join(f"`{i}`" for i in self.mapper.keys())
            )
        if len(self.mapper[dept]) == 1:
            batch = 1
        elif not batch or batch not in (1, 2):
            return await ctx.send("Kindly enter whether batch 1 or 2")

        async with self.config.user_from_id(ctx.author.id).all() as user_data:
            user_data["dept"] = dept
            user_data["batch"] = batch

        await ctx.send(
            f"Sucessfully registered as department {dept}"
            + (f" and batch {batch}" if batch else "")
        )

    # Util function to get subject_object
    def get_sub_obj(self, dept, batch=None):
        mini = self.mapper[dept]
        if not batch:
            batch = 1
        return mini[batch - 1]

    @commands.command()
    async def leaves(self, ctx, verbose: bool = False):
        """Get the list of holidays for fun"""
        holidays = ""
        time_now = dt.datetime.now(tz=gettz("Asia/Kolkata"))
        tmrw = time_now + dt.timedelta(days=1)
        while True:
            try:
                if res.day_order[tmrw.strftime("%Y-%m-%d")][-1] == "0":
                    if verbose or not tmrw.weekday() in (5, 6):
                        holidays += f"{tmrw.strftime('`%d/%m/%y` : **%A**')}\n"
                tmrw += dt.timedelta(days=1)
            except KeyError:
                break

        embs = []
        pages = list(cf.pagify(holidays, page_length=1000, shorten_by=0))
        no_of_pages = len(pages)
        for pgno, page in enumerate(pages, 1):
            embs.append(
                discord.Embed(title="Holiday Calender", description=page).set_footer(
                    text=f"Page {pgno}/{no_of_pages}"
                )
            )

        await menu(
            ctx,
            pages=embs,
            controls=DEFAULT_CONTROLS
            if len(embs) > 1
            else {"\N{CROSS MARK}": DEFAULT_CONTROLS["\N{CROSS MARK}"]},
        )

    @commands.command(aliases=["tt"])
    async def timetable(self, ctx, dept: str = None, batch: int = None):
        """`[p]timetable department` displays the timetable of the department

        Available departments:
        - aids2
        - cse2c
        - cse3b
        - cse3c
        - mtech2
        Others:
        - srm
        """

        user_data = await self.config.user_from_id(ctx.author.id).all()
        time_now = dt.datetime.now(tz=gettz("Asia/Kolkata"))
        day_order = res.day_order[time_now.strftime("%Y-%m-%d")]

        if not dept:
            if user_data["dept"] and user_data["batch"]:
                dept = user_data["dept"]
                batch = int(user_data["batch"])
            else:
                return await ctx.send_help()
        else:
            if dept not in self.mapper.keys():
                return await ctx.send(
                    "Invalid department. Please choose from:\n"
                    + ", ".join(f"`{i}`" for i in self.mapper.keys())
                )
            if len(self.mapper[dept]) == 1:
                batch = 1
            elif not batch or batch not in (1, 2):
                return await ctx.send(
                    f"Kindly enter whether batch 1 or 2\n Example: {ctx.message.content.split(' ')[0]} aids2 1"
                )

        if dept not in self.mapper:
            return await ctx.send_help()

        table = tabulate(
            [
                [k + " -->" if day_order == k else k] + [period for period in v]
                for k, v in self.get_sub_obj(dept, batch).items()
            ],
            headers=["", "9:30", "10:30", "1:30", "2:30", "3:30"],
            tablefmt="presto",
            colalign=("left",),
        )

        return await menu(
            ctx,
            [f"{self.title_map[dept]}  **Batch {batch}** TimeTable```{table}```"],
            {"\N{CROSS MARK}": DEFAULT_CONTROLS["\N{CROSS MARK}"]},
        )

    @commands.command(aliases=["links"], usage="[dept] [batch]")
    async def link(self, ctx, dept=None, batch: int = None, ext=None):
        """Get the link to the gmeet of your department

        Connect your class using `[p]connect` or else give your department and batch number

        Available departments:
        - aids2
        - cse2c
        - cse3b
        - cse3c
        - mtech2
        """
        is_dm = type(ctx) is int
        user_data = await self.config.user_from_id(ctx if is_dm else ctx.author.id).all()
        if not dept:
            if user_data["dept"] and user_data["batch"]:
                dept = user_data["dept"]
                batch = int(user_data["batch"])
            else:
                return await ctx.send_help()
        else:
            if dept not in self.mapper.keys():
                return await ctx.send(
                    "Invalid department. Please choose from:\n"
                    + ", ".join(f"`{i}`" for i in self.mapper.keys())
                )
            if len(self.mapper[dept]) == 1:
                batch = 1
            elif not batch or batch not in (1, 2):
                return await ctx.send("Kindly enter whether batch 1 or 2")

        # Prep stuff
        embs = []

        # Getting correct time things
        time_now = ext if ext else dt.datetime.now(tz=gettz("Asia/Kolkata"))
        day_order = res.day_order[time_now.strftime("%Y-%m-%d")]

        # Get next working day
        tmrw = time_now + dt.timedelta(days=1)
        while res.day_order[tmrw.strftime("%Y-%m-%d")][-1] == "0":
            tmrw += dt.timedelta(days=1)

        # Hardcoded timedelta
        next_class_day = tmrw.replace(hour=9, minute=30) - time_now

        # Holiday
        if day_order[-1] == "0":
            if is_dm:
                return None
            emb = discord.Embed(
                title="Holiday",
                description=f"Next class in {cf.humanize_timedelta(timedelta=next_class_day)}",
                color=discord.Color.orange(),
            )

            emb.set_footer(
                text=f"Next day order {res.day_order[(time_now + next_class_day).strftime('%Y-%m-%d')]}"
            )

            # emb.add_field(name="Your first class on the next working day", value=sub[0])
            embs.append(emb)

        # Working day :(
        else:
            emb = discord.Embed(color=discord.Color.green())
            emb.set_footer(text=f"{day_order}  |  Batch-{batch}")
            emb.set_author(name=self.title_map[dept])
            dept_links = getattr(res, dept + "_links")

            sub_obj = self.get_sub_obj(dept, batch)[day_order]
            time_obj = time_now.time()
            # time_obj = dt.time(16, 28) #debug

            # Before First class
            if time_obj < self.ref_time[0]:
                subject = sub_obj[0]
                emb.add_field(
                    name="Upcomming class",
                    value=f"**{subject}**\n Start time: `{self.ref_time[0].strftime('%I:%M %p')}`\n [Google-Meet-link]({dept_links[subject]})",
                )

            else:
                for hr_index in range(len(self.ref_time) - 1):
                    if self.ref_time[hr_index] <= time_obj < self.ref_time[hr_index + 1]:
                        subject = sub_obj[hr_index]
                        end_time = (
                            dt.datetime.combine(
                                dt.date.today(), self.ref_time[hr_index])
                            + dt.timedelta(hours=1)
                        ).time()
                        emb.add_field(
                            name=(
                                "Ongoing"
                                if end_time > time_obj or end_time == self.ref_time[hr_index + 1]
                                else "Past"
                            )
                            + " class",
                            value=f"**{subject}**\n End time: `{end_time.strftime('%I:%M %p')}`\n [Google-Meet-link]({dept_links[subject]})",
                        )

                        # There exists a next class
                        if hr_index < len(sub_obj) - 1:
                            subject = sub_obj[hr_index + 1]
                            if subject != "NILL":
                                emb.add_field(
                                    name="Upcoming class",
                                    value=f"**{subject}**\n Start time: `{self.ref_time[hr_index+1].strftime('%I:%M %p')}`\n [Google-Meet-link]({dept_links[subject]})",
                                )
                            elif is_dm and subject == "NILL":
                                return None
                        break
                else:
                    subject = sub_obj[-1]
                    # We are in the last hour
                    if (
                        time_obj
                        < dt.time(hour=self.ref_time[-1].hour + 1, minute=self.ref_time[-1].minute)
                        and subject != "NILL"
                    ):
                        if is_dm:
                            return None
                        emb.add_field(
                            name="Ongoing class",
                            value=f"**{subject}**\n *End time:* {self.ref_time[-1].strftime('%I:%M %p')} \n [Google-Meet-link]({dept_links[subject]})",
                        )

                if len(emb.fields) <= 1 and is_dm:
                    return None

                if len(emb.fields) <= 1:
                    emb.add_field(
                        name="End",
                        value=f"Next class in {cf.humanize_timedelta(timedelta=next_class_day)}",
                    )
            embs.append(emb)

        # For now there is only one page, let's add more later
        if not is_dm:
            await menu(
                ctx,
                embs,
                DEFAULT_CONTROLS
                if len(embs) > 1
                else {"\N{CROSS MARK}": DEFAULT_CONTROLS["\N{CROSS MARK}"]},
            )
        else:
            return embs[0]

    # rollnum cogs added here
    @commands.command()
    async def pnum(self, ctx, option):
        emb = discord.Embed(title="Details")
        emb.set_image(url=f"https://samwyc.codes/images/{option}.jpg")
        await menu(ctx, [emb], {"\N{CROSS MARK}": DEFAULT_CONTROLS["\N{CROSS MARK}"]})

    @commands.command()
    async def rn(self, ctx, option):
        """displays the details of roll number provided"""
        o = option.upper()
        # data.loc[data["r_no"]=='17EUCS001']
        # await ctx.send(self.data)
        d = self.data.loc[self.data["r_no"] == o]
        if len(d):
            emb = discord.Embed(title="Details")
            emb.add_field(
                name="Name",
                value=str(d.iloc[0]["name"]) + " " + str(d.iloc[0]["s_name"]),
            )
            emb.add_field(name="Department", value=d.iloc[0]["dept"])
            emb.add_field(name="Roll No", value=d.iloc[0]["r_no"])
            emb.set_image(url=f"https://samwyc.codes/images/{option}.jpg")
            await menu(ctx, [emb], {"\N{CROSS MARK}": DEFAULT_CONTROLS["\N{CROSS MARK}"]})
            """
            res='''`Name` {n} {n1}\n`Dept` {d1}\n`Roll` {r}'''.format(n=(d.iloc[0])["name"],n1=(d.iloc[0])["s_name"],d1=(d.iloc[0])["dept"],r=(d.iloc[0])["r_no"])
            await ctx.send(res)"""
        else:
            await ctx.send("Not found")

    @commands.command()
    async def rnum(self, ctx, rollnumber: str):
        """Get detailed information about the given rollnumber of a person"""

        head1 = {
            "user-agent": "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36"
        }
        head2 = {
            "User-Agent": "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:89.0) Gecko/20100101 Firefox/89.0",
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
            "Accept-Language": "en-US,en;q=0.5",
            "Content-Type": "application/x-www-form-urlencoded",
            "Origin": "https://pgw.srikrishna.ac.in",
            "Connection": "keep-alive",
            "Referer": "https://pgw.srikrishna.ac.in/index.php/?key=tyut54yh56thtgh",
            "Upgrade-Insecure-Requests": "1",
        }
        async with ctx.typing():
            async with aiohttp.ClientSession() as session:
                async with session.get(
                    "https://pgw.srikrishna.ac.in/index.php/?key=tyut54yh56thtgh",
                    headers=head1,
                ) as resp:
                    if resp.status != 200:
                        return await ctx.send("Server down, try again later")
                async with session.post(
                    "https://pgw.srikrishna.ac.in/index.php/Welcome/Dashboard",
                    headers=head2,
                    data={"RollNo": rollnumber},
                ) as resp:
                    if resp.status != 200:
                        return await ctx.send("Server down, try again later")
                    soup = BeautifulSoup(await resp.text(), "html.parser")
                emb = discord.Embed(
                    title="Something went wrong, User not found",
                    color=await ctx.embed_color(),
                )
                for thing in soup.findAll(id=lambda L: L and L.startswith("student_")):
                    emb.add_field(
                        name=thing["id"].replace("student_", "").capitalize(),
                        value=thing.text.title(),
                    )
                    if thing["id"] == "student_name":
                        emb.title = thing.text.split(
                        )[0].capitalize() + "'s Details"
                emb.set_thumbnail(
                    url=f"https://samwyc.codes/images/{rollnumber}.jpg")
                await ctx.send(embed=emb)

    @commands.command()
    async def sname(self, ctx, option):
        """search by name"""
        a = option.upper()
        # d=self.data.loc[self.data["name"]==a]
        d = self.data[self.data["name"].str.contains(a, na=False)]
        i = 1

        table = []

        # search by first name
        for index, k in d.iterrows():
            table.append([i, str(k["name"]) + " " +
                         str(k["s_name"]), k["dept"], k["r_no"]])
            i += 1

        # search in second name
        d = self.data[self.data["s_name"].str.contains(a, na=False)]
        for index, k in d.iterrows():
            table.append(
                [i, k["name"] + " " + k["s_name"], k["dept"], k["r_no"]])
            i += 1

        i = len(table)
        if i:
            li = list(
                cf.pagify(
                    tabulate(
                        table,
                        headers=["Sno", "Name", "Department", "Roll no"],
                        tablefmt="presto",
                        colalign=("left",),
                    ),
                    page_length=1900,
                )
            )
            n = len(li)
            await menu(
                ctx,
                [f"```{i} ```" + f"**> Page {j+1} / {n}**" for j,
                    i in enumerate(li)],
                DEFAULT_CONTROLS,
            )
        else:
            await ctx.reply("No name matched with the data base")

    @commands.command()
    async def aids(self, ctx, options: int):
        """get details of students of AIDS"""

        # data.loc[data["r_no"]=='17EUCS001']
        # await ctx.send(self.data)
        d = self.ai_data.loc[self.ai_data["S_No"] == options]
        if len(d):
            emb = discord.Embed(
                title="Details", color=discord.Color.dark_green())
            emb.add_field(name="Name", value=d.iloc[0]["Name"])
            emb.add_field(name="DOB", value=d.iloc[0]["DOB"])
            emb.add_field(name="Mobile", value=d.iloc[0]["Student_cell"])
            emb.add_field(name="Email", value=d.iloc[0]["Email_id"])
            emb.add_field(name="Address", value=d.iloc[0]["Per_Address"])

            # emb.set_image(url=f"https://samwyc.codes/images/20euai{options:03}.jpg")
            await menu(ctx, [emb], {"\N{CROSS MARK}": DEFAULT_CONTROLS["\N{CROSS MARK}"]})

        else:
            await ctx.send("Not found")

    @commands.command()
    async def resai(self, ctx, serialnum: int):
        """display the result of semester happened in apr/mar"""
        month = {
            "Jan": "01",
            "Feb": "02",
            "Mar": "03",
            "Apr": "04",
            "May": "05",
            "Jun": "06",
            "Jul": "07",
            "Aug": "08",
            "Sep": "09",
            "Oct": "10",
            "Nov": "11",
            "Dec": "12",
        }

        d = self.ai_data.loc[self.ai_data["S_No"] == serialnum]

        if len(d) == 0:
            return await ctx.reply("Wrong serial number")

        dd = str(d.iloc[0]["DOB"]).split("-")
        dd[0], dd[1] = month[dd[1]], dd[0]
        dd = "/".join(dd)
        await self.result(ctx, f"20euai{serialnum:03}", dd)

    @commands.command()
    async def result(self, ctx, rollnum: str, dob: str):
        """display the result of semester happened in apr/mar"""
        async with ctx.typing():
            rollnum = rollnum.upper()

            dd = re.match(
                "[0-9]{2}/[0-9]{2}/(1998|1999|2000|2001|2002|2003|2004)", dob)
            if dd == None:
                await ctx.reply("Wrong dob Pattern")
                return

            r_form_data = {"Srollno": rollnum, "Password": dob}

            r_headers = {
                "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
                "Accept-Encoding": "gzip, deflate",
                "Accept-Language": "en-US,en;q=0.5",
                "Connection": "keep-alive",
                "Content-Length": "41",
                "Content-Type": "application/x-www-form-urlencoded",
                # "Cookie": "ci_session=8geukb5t1h4t3nkqo82fa7l2l9ok49qi",
                "Host": "results.skcet.ac.in:612",
                "Origin": "http://results.skcet.ac.in:612",
                "Referer": "http://results.skcet.ac.in:612/",
                "Upgrade-Insecure-Requests": "1",
                "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:91.0) Gecko/20100101 Firefox/91.0",
            }
            r = requests.post(
                "http://results.skcet.ac.in:612/index.php/Welcome/Login",
                data=r_form_data,
                headers=r_headers,
            )
            if (
                b"http://results.skcet.ac.in:612/assets/StudentImage/"
                + bytes(rollnum, encoding="utf8")
                not in r.content
            ):
                await ctx.reply("Wrond dob or rollnum: " + rollnum + "," + dob)
                return

            try:
                r.cookies.get_dict()["ci_session"]
            except:
                await ctx.reply("There was a error loading the details")
                return

            r_headers1 = {
                "Host": "results.skcet.ac.in:612",
                "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:91.0) Gecko/20100101 Firefox/91.0",
                "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
                "Accept-Language": "en-US,en;q=0.5",
                # 'Accept-Encoding': 'gzip, deflate',
                "Connection": "keep-alive",
                "Referer": "http://results.skcet.ac.in:612/index.php/Welcome/Login",
                # 'Cookie': 'ci_session=mtq22fefrtr9l6l8djcjircu375h0mro',
                "Cookie": "ci_session=" + r.cookies.get_dict()["ci_session"],
                "Upgrade-Insecure-Requests": "1",
            }

            r1 = requests.post(
                "http://results.skcet.ac.in:612/index.php/Result",
                cookies=r.cookies,
                headers=r_headers1,
            )
            soup = BeautifulSoup(r1.content, "html.parser")
            if soup.findAll("tr") == []:
                """expection with cookies"""
                r_headers1 = {
                    "Host": "results.skcet.ac.in:612",
                    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:91.0) Gecko/20100101 Firefox/91.0",
                    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
                    "Accept-Language": "en-US,en;q=0.5",
                    # 'Accept-Encoding': 'gzip, deflate',
                    "Connection": "keep-alive",
                    "Referer": "http://results.skcet.ac.in:612/index.php/Welcome/Login",
                    # 'Cookie': 'ci_session='+r.cookies.get_dict()['ci_session'],
                    "Cookie": "ci_session=mtq22fefrtr9l6l8djcjircu375h0mro",
                    "Upgrade-Insecure-Requests": "1",
                }
                r1 = requests.post(
                    "http://results.skcet.ac.in:612/index.php/Result",
                    cookies=r.cookies,
                    headers=r_headers1,
                )
                soup = BeautifulSoup(r1.content, "html.parser")
                if soup.findAll("tr") == []:
                    await ctx.reply("Temporarry fix broken")
                    return
                # await ctx.send(str(soup.text)[:1999])
                # await ctx.send(str(soup.p.text))
                # await ctx.reply(f"bru Literally,... The site dont have the result of {rollnum}")

            b = []
            for i in soup.findAll("tr"):
                a = i.findAll("td")
                s = []
                for j in a:
                    if len(j) == 3:
                        j = j.find("span").contents
                    s.extend(j)
                b.append(s)

            try:
                await ctx.send(
                    "***"
                    + soup.p.text
                    + "***"
                    + "```"
                    + tabulate(b[1:], headers=b[0],
                               tablefmt="presto", colalign=("left",))
                    + "```"
                )
            except:
                await ctx.send(f"Somthing went wrong at the last moment")
