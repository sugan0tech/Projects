    if tree != None:
        inorder(tree.left)
        print(tree.val, " ", end="")
        inorder(tree.right)

def preorder(tree, arr):
    if tree != None:
        arr.append(tree.val)
