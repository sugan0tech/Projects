class BstNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, num):
        if not self.data:
            self.data = num
            return

        if self.data == num:
            return
        if self.data < num:
            if self.right:
                self.right.insert(num)
                return
            self.right = BstNode(num)
            return

        if self.left:
            self.left.insert(num)
            return
        self.left = BstNode(num)
    

    def inorder(self):
        if self.data :
            if self.left:
                self.left.inorder()
            print(self.data, end=' ')
            if self.right:
                self.right.inorder()

    def max(self):
        temp = self
        while temp.right:
            temp = temp.right
        print(temp.data)

    def min(self):
        temp = self
        while temp.left:
            temp = temp.left
        print(temp.data)

    def preorder(self):
        if self.data :
            print(self.data, end=' ')
            if self.left:
                self.left.preorder()
            if self.right:
                self.right.preorder()


    def postorder(self):
        if self.data :
            if self.left:
                self.left.postorder()
            if self.right:
                self.right.postorder()
            print(self.data, end=' ')

    def add(self, key):
        if self is None:
            self = BstNode(key)
        
        if self.data == key:
            return self
        
        if key < self.data:
            if self.left:
                self.left = self.left.add(key)
            else:
                self.left = BstNode(key)
        else:
            if self.right:
                self.right = self.right.add(key)
            else:
                self.right = BstNode(key)
        return self
    
    def delete(self, key):
        if self is None:
            return self
        
        if key < self.data:
            if self.left:
                self.left.delete(key)
        elif key > self.data :
            if self.right:
                self.right.delete(key)

        
opt = int(input("Enter the option :"))
tree = BstNode(6)
while opt:
    if opt == 1:
        num = int(input("enter the node val"))
        while num != -1:
            tree.insert(num)
            num = int(input("enter the node val"))
    if opt == 2:
        print("Tree Inorder : { ", end='')
        tree.inorder()
        print("}")
        print("Tree Preorder : { ", end='')
        tree.preorder()
        print("}")
        print("Tree Postorder : { ", end='')
        tree.postorder()
        print("}")
    if opt == 3:
        tree.max()
        tree.min()
        tree.add(87)
    opt = int(input("enter the option :"))