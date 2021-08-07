class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
        self.pre = None
    
class LinkedList:
    def __init__(self):
        self.Head = None
    
    def printl(self):
        temp = self.Head
        while temp.next:
            print(temp.data, " -> ", end='')
            temp = temp.next

        print(temp.data)
        temp = temp.pre
        while temp:
            print(temp.data, " -> ", end='')
            temp = temp.pre

llist = LinkedList()
llist.Head = Node(8)
temp = llist.Head
for i in range(3):
    num = int(input("enter the num"))
    temp.next = Node(num)
    temp.next.pre = temp
    temp = temp.next

llist.printl()
