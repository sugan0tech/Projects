class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
    
    def __str__(self):
        return f"{self.data}"


class LinkedList:
    def __init__(self):
        self.Head = None
    
    def print_llist(self):
        temp = self.Head
        while temp:
            print(temp.data, " -> ", end='')
            temp = temp.next
        print(None)

    def create(self):
        num = int(input("Enter the Node data :"))
        new = Node(num)
        temp = LinkedList()
        while num != -1:
            if self.Head == None:
                self.Head = new
                temp = self.Head
            else:
                temp.next = new
                temp = temp.next
            num = int(input("Enter the Node data :"))
            new = Node(num)
        
        return self
        
    def insert(self):
        num = int(input("Enter the data to be inserted"))
        new = Node(num)
        opt = int(input(print("1. for head insertion\n2. for tail insertion\n3. for intermediate insertion\n")))
        if opt == 1:
            temp = self.Head
            self.Head = new
            self.Head.next = temp
            return self
        elif opt == 2:
            temp  = self.Head
            while temp.next.next:
                temp = temp.next
            temp.next = new
            return self
        else:
            num = int(input("Enter the Node to be before :"))
            temp = self.Head
            while temp.next:
                if temp.data == num:
                    break
                
                temp = temp.next
            nxt = temp.next
            temp.next = new
            temp = temp.next
            temp.next = nxt

            return self

    def delete(self):
        opt = int(input(print("1. for head deletion\n2. for tail deletion\n3. for intermediate deletion\n")))
        if opt == 1:
            temp = self.Head.next
            self.Head = temp
            return self
        elif opt == 2:
            temp  = self.Head
            while temp.next.next:
                temp = temp.next
            temp.next = None
            return self
        else:
            num = int(input("Enter the Node to be deleted :"))
            temp = self.Head
            while temp.next:
                if temp.data == num:
                    pre.next = temp.next
                
                pre = temp
                temp = temp.next
            return self

    def __str__(self):
        return f"LinkedList|> Head: {self.Head}"


tst = LinkedList().create()
tst.insert()
tst.print_llist()
tst.insert()
tst.print_llist()
print(tst)