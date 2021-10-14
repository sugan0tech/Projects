from matplotlib import pyplot as plt
a=[10,20,30,40,50]
b=[2,4,6,8,10]
c=[5,10,15,20,25]
d=[4,8,12,16,20]
plt.plot(a,b, label='ALLUVIAL SOIL',linewidth=3,color='green')
plt.plot(a,c, label='MOUNTAIN SOIL',linewidth=3,color='orange')
plt.plot(b,d,label='DESERT SOIL',linewidth=3,color='blue')
plt.title('soil level')
plt.xlabel('soil fertility')
plt.ylabel('soil level')
plt.legend()
plt.show()