import time
for i in range(1000):
    time.sleep(0.001)
    print(f"% {i} \r", end='')