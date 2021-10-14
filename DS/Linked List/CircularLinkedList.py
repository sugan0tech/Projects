class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
    

class DoubleLinkedList:
    def __init__(self):
        self.head = None
    
    def printd(self):
        temp = self.head
        print("Head :", end=' ')
        print(temp.data, "->", end=' ')
        temp = temp.next
        while temp != self.head:
            print(temp.data, "->", end=' ')
            temp = temp.next
        print(f"{self.head.data} : Head")

    def create(self):
        num = int(input("Enter the Node val :"))
        new = Node(num)
        while num:
            if self.head == None:
                self.head = new
                self.head.next = self.head
                temp = self.head
            else:
                temp.next = new
                temp = new
                temp.next = self.head

            num = int(input("Enter the Node val :"))
            new = Node(num)

        
llsit = DoubleLinkedList()
llsit.create()
llsit.printd()
print("----*----*----*----*----*----");
print("Thanks for using this code :)");
print("----*----*----*----*----*----");
#Done by sugan0tech