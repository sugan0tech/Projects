class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    def print_bst(self):
        if self.root:
            self._print_bst(self.root)
    
    def _print_bst(self, node):
        if node:
            self._print_bst(node.left)
            print(node.data, end=" ")
            self._print_bst(node.right)

    def create(self, num):
        if self.root is None:
            self.root = Node(num)
        else:
            self._create(self.root, num)
        
    def _create(self, node, num):
        
        if num > node.data:
            if node.right is None:
                node.right = Node(num)
            else:
                self._create(node.right, num)
        elif num == node.data:
            pass;
        else:
            if node.left is None:
                node.left = Node(num)
            else:
                self._create(node.left, num)

    def height(self):
        if self.root:
            return self._height(self.root, 0)
        else:
            return 0
    
    def _height(self, node, cur_height):
        if node == None:
            return cur_height
        else:
            left_height = self._height(node.left, cur_height + 1)
            right_height = self._height(node.right, cur_height + 1)
        return max(left_height, right_height)
    
    def _min(self, node):
        while node.left is not None:
            node = node.left
        return node.data

    def _max(self, node):
        while node.right is not None:
            node = node.right
        return node.data
    
    def minmax(self):
        print("Min val :", self._min(self.root))
        print("Max val :", self._max(self.root))
    
    def delete(self):
        num = int(input("Enter the Node to be deleted :"))
        self.root = self._delete(self.root, num)
    
    def _delete(self, node, num):
        if node is None:
            return node
        if node.data > num:
            node.left = self._delete(node.left, num)
        elif node.data < num:
            node.right = self._delete(node.right, num)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            
            temp = Node(self._minum(node.right))
            self.data = temp.data
            self.right = self._delete(node.right, temp.data)
        
        return node






tree = BinarySearchTree()
tree.root = Node(10)
for i in range(2, 30):
    tree.create(i)

tree.print_bst()

print("\n", tree.height())
tree.minmax()
tree.delete()
tree.print_bst()
print("\n", tree.height())