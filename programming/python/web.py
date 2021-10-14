import requests
import random
from bs4 import BeautifulSoup as bs

url = "https://free-proxy-list.net/"
soup = bs(requests.get(url).content, "html.parser")
proxies = []
for row in soup.find("table", attrs={"id":"proxylisttable"}).find_all("tr")[1:]:
    tds = row.find_all("td")
    try: 
        ip = tds[0].text.strip()
        port = tds[1].text.strip()
        host = str(ip) + ":" + str(port)
        proxies.append(host)
    except IndexError:
        continue
print(proxies)

def get_session(proxies):
    session = requests.Session()
    proxy = random.choice(proxies)
    session.proxies = {"http":proxy, "https": proxy}
    return session

for i in proxies: 
    s = get_session(proxies)
    try:
        print("Request page with IP:", s.get("http://icanhazip.com", timeout=1.5).text.strip())
    except Exception as e:
        continue
