from tkinter import *
import math
import parser
import tkinter.messagebox

root = Tk()
root.title("Scientific Calculator")
root.configure(background ="powder blue")
root.resizable(width =False, height=False)
root.geometry("480x568+0+0")

calc =Frame(root)
calc.grid()

#=================================================Menu===============================
def iExit():
    iExit = tkinter.menu


menubar = Menu(calc)

filemenu = Menu(menubar, tearoff =0)
menubar.add_cascade(label="File",menu=filemenu)
filemenu.add_command(label= "Standard")
filemenu.add_command(label= "Scientific")
filemenu.add_separator()
filemenu.add_command(label= "Exit")

editmenu = Menu(menubar, tearoff =0)
menubar.add_cascade(label="Edit",menu=editmenu)
editmenu.add_command(label= "Cut")
editmenu.add_command(label= "Copy")
editmenu.add_separator()
editmenu.add_command(label= "Paste")

helpmenu = Menu(menubar, tearoff =0)
menubar.add_cascade(label="Edit",menu=helpmenu)
helpmenu.add_command(label= "view help")

root.config(menu=menubar)
root.mainloop()