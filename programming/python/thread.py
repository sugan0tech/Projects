import threading
import sys
import time
print("hi")
time.sleep(0.1)
print("j")
for i in range(10):
    time.sleep(0.1)
    print(i)
progress = 12
d = 23
i = 0
while i <= 100.0:
    time.sleep(0.001)
    print('Downloading File FooFile.txt [%f%%]\r'%i, end="")
    i += 0.1
print("\n")
for i in range(101):
    time.sleep(0.01)
    print("Downloading [%d%%]\r"%i, end="")
print("\n")
i = 0
t = 0
while i <= 100:
    if i%2 == 0:
        j = "\\"
    if i%2 == 1:
        j = "|"
    if t%3 == 0:
        j = "/"
    time.sleep(0.1)
    print("[%s%%]\r"%j, end="")
    i += 1
    t += 2
