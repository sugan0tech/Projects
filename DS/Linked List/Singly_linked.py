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
        print("")
        while temp:
            print(temp.data, " -> ", end='')
            temp = temp.next
        print(None)

    def create(self):
        num = int(input("\nEnter the Node data :"))
        new = Node(num)
        while num != -1:
            new = Node(num)
            if self.Head == None:
                self.Head = new
                temp = self.Head
            else:
                temp.next = new
                temp = temp.next
            num = int(input("Enter the Node data :"))
        return self
        
    def insert(self):
        num = int(input("\nEnter the data to be inserted"))
        print("\n1. for head insertion\n2. for tail insertion\n3. for intermediate insertion")
        opt = int(input("Enter the option\n"))
        new = Node(num)
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
            num = int(input("\nEnter the Node to be before :"))
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
        opt = int(input(print("\n1. for head deletion\n2. for tail deletion\n3. for intermediate deletion\n")))
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
            num = int(input("\nEnter the Node to be deleted :"))
            temp = self.Head
            while temp.next:
                if temp.data == num:
                    pre.next = temp.next
                
                pre = temp
                temp = temp.next
            return self

    def __str__(self):
        return f"\nLinkedList|> Head: {self.Head}"


if __name__ == "__main__":

    L_list = LinkedList()
    print("\n0. for exit\n1. for creation\n2. for printing\n3. for insertion\n4. for deletion")
    option = int(input("Enter your option :"))
    while option:
        if option == 1:
            L_list = L_list.create()
        elif option == 2:
            L_list.print_llist()
        elif option == 3:
            L_list = L_list.insert()
        elif option == 4:
            L_list = L_list.delete()
        else:
            print(L_list)
            print("Wrong option")
        print("\n0. for exit\n1. for creation\n2. for printing\n3. for insertion\n4. for deletion")
        option = int(input("Enter your option :"))
        