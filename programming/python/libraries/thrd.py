import threading
data = threading.local()
data.x = 1
print(threading.active_count())
print(threading.enumerate())
print(threading.stack_size())