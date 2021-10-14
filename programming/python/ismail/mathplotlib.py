from matplotlib import pyplot as plt
a=[1,2,3,4,5,]
b=[5,10,15,20,25]
c=[2,4,6,8,10]
plt.plot([],[],color='x',label='Run',linewidth=4)
plt.plot([],[],color='y',label='walk',linewidth=4)
plt.plot([],[],color='z',label='jog',linewidth=4)
plt.stackplot(a,b,c,colors=['x','y','z'])
plt.xlabel('x')
plt.ylabel('y')
plt.title('Bar Chart')
plt.legend()
plt.show()
