from tkinter import *
window=Tk()
l=Label(window,text='USER NAME: ')
l.grid(row=1,column=1)
a=StringVar()
e=Entry(window,text=a)
e.grid(row=1,column=2)
l1=Label(window,text='E-MAIL ID: ')
l1.grid(row=2,column=1,sticky=W)
b=StringVar()
e1=Entry(window,text=b)
e1.grid(row=2,column=2)
l2=Label(window,text='PASSWORD: ')
l2.grid(row=3,column=1)
c=StringVar()
e2=Entry(window,show='*',text=c)
e2.grid(row=3,column=2)
def act():
    x=a.get()
    y=b.get()
    z=c.get()
    print('NAME',x)
    print('E -MAIL ID',y)
    print('PASSWORD',z)
bt=Button(window,text='SUBMIT',command=act)
bt.grid(row=6,column=5)
window.mainloop()
