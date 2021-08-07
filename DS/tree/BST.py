from binarytree import build
import random

class Node:
    def __init__(self, value = None, right = None, left = None):
        self.val = value
        self.left = left
        self.right = right
        

def inorder(tree):
    if tree != None:
        inorder(tree.left)
        print(tree.val, " ", end="")
        inorder(tree.right)
def preorder(tree):
    if tree != None:
        print(tree.val, " ", end="")
        preorder(tree.left)
        preorder(tree.right)

def create(root, data):
    if root.val > data:
        if root.right is None:
            root.right = Node(data)
        else:
            create(root.right, data)
    else:
        if root.left is None:
            root.left = Node(data)
        else:
            create(root.left, data)

root = Node(10)
for i in range(1, 20):
    create(root, i)



inorder(root)
preorder(root)
print(root)

treelst = []
for i in range(0, 25):
    treelst.append(random.randint(0, 100))

binary = build(treelst)

print(binary)