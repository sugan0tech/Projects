class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
        self.pre = None
    

class DoubleLinkedList:
    def __init__(self):
        self.head = None
    
    def print(self):
        temp = self.head
        print("Head :", end=' ')
        while temp.next:
            print(temp.data, "->", end=' ')
            temp = temp.next
        print(f"{temp.data} -> None")
        print("None ->", end=' ')
        while temp != self.head:
            print(temp.data, "->", end=' ')
            temp = temp.pre
        print(f"{self.head.data} : Head")

    def create(self):
        num = int(input("Enter the Node val :"))
        new = Node(num)
        while num:
            if self.head == None:
                self.head = new
                temp = self.head
            else:
                temp.next = new
                new.pre = temp
                temp = new

            num = int(input("Enter the Node val :"))
            new = Node(num)

        
llsit = DoubleLinkedList()
llsit.create()
llsit.print()
print("----*----*----*----*----*----");
print("Thanks for using this code :)");
print("----*----*----*----*----*----");
#Done by sugan0tech