class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
class BinaryTree:
    def __init__(self):
        self.root = None
    
    def create(self):
        num = int(input('Enter the node data -1 for None'))
        new = Node(num)
        if num == -1:
            return None
        if self.root == None:
            self.root = new
        
        num = int(input('Enter the node for left'))
        new.left = self.create()
        num = int(input('Enter the node for right'))
        new.right = self.create()
        return new
    def inorder(self, root):
        if root != None:
            self.inorder(root.left)
            print(root.data)
            self.inorder(root.right)
        else:
            print(None)
        

opt = int(input('Options'))
tree = BinaryTree()
while opt:
    if opt == 1:
        tree = tree.create()
    if opt == 2:
        tree.inorder(tree)

    opt = int(input('Options'))
