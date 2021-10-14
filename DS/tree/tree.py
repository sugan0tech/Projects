class Node:
    def __init__(self, data, left, right):
        self.data = data
        self.left = left
        self.right = right

def create():
    t = Node(None, None, None)
    x = int(input('Enter the num :'))
    if x == -1:
        return None

    t.data = x
    print(f"left Child of {x}")
    t.left = create()
    print(f"right Child of {x}")
    t.right = create()
    return t

def inorder(tree):
    if tree != None:
        inorder(tree.left)
        print(f"{tree.data} ", end='')
        inorder(tree.right)

def preorder(tree):
    if tree != None:
        print(f"{tree.data} ", end='')
        preorder(tree.left)
        preorder(tree.right)

def form(pre_start, in_start, in_end, pre_order, in_order):
    if((pre_start > len(pre_order) - 1) or (in_start > in_end)):
        return None

    root = Node(pre_order[pre_start], None, None)
    in_index = 0
    for i in range(in_start, in_end):
        if root.data == in_order[i]:
            in_index = i

    root.left = form(pre_start + 1, in_start, in_index - 1, pre_order, in_order)
    root.right = form(pre_start + in_index - in_start + 1, in_index - 1, in_end, pre_order, in_order)
    return root
    




# var = create()
# inorder(var)
# print("\n---break---")
# preorder(var)
var = form(0, 0, 4, [3, 9, 20, 15, 7], [9, 3, 15, 20, 7])
inorder(var)
print(" ")
preorder(var)