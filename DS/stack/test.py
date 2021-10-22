class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def create(self, num):
        if not self.data:
            self.data = num
            return
        
        if self.data == num:
            return
        if num > self.data:
            if self.right:
                self.right.create(num)
                return
            self.right = Node(num)
            return
        if self.left:
            self.left.create(num)
            return
        self.left = Node(num)
        return


    def inorder(self):
        if self.data:
            if self.left:
                self.left.inorder()
            print(self.data, end=' ')
            if self.right:
                self.right.inorder()

tree = Node(10)
for i in range(80):
    tree.create(i)


tree.inorder()