class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
    
class LinkedList:
    def __init__(self):
        self.Head = None
    
    def printl(self):
        temp = self.Head
        while temp:
            print(temp.data, " -> ", end='')
            temp = temp.next

def dequeue(Head:LinkedList) -> LinkedList:
    temp = Head.next
    Head = temp
    return Head

def enqueue(Head:LinkedList, data) -> LinkedList:
    temp = Head
    while temp.next:
        temp = temp.next
    temp.next = Node(data)

    return Head
    

def switch(key:int):
    dict = {
        1 : "one",
        2 : "two",
        3 : "three" 
    }
    return dict.get(key)


print(switch(2))