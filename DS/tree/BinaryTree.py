class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        

def create():
    num =  int(input("enter the node val"))
    if num == -1:
        return None
    new = TreeNode(num)
    print(f"Enter the left child for {new.data} :")
    new.left = create()
    print(f"Enter the right child for {new.data} :")
    new.right = create()
    return new

def inorder(tree):
    if tree != None:
        inorder(tree.left)
        print(tree.data)
        inorder(tree.right)
    else :
        print("None")

opt = int(input("Enter the option"))
while opt:
    if opt == 1:
        tree = create()
    if opt == 2:
        inorder(tree)
    opt = int(input("enter the option"))