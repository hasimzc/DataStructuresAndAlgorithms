class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    def insert(self,data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            else:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data
    def inorderTraversal(self,root):
        res = []
        if root:
            res += self.inorderTraversal(root.left)
            res.append(root.data)
            res += self.inorderTraversal(root.right)
        return res
    def isSymmetric(self):
        if self.inorderTraversal(root.left) == self.inorderTraversal(root.right):
            return True
        return False
root = Node(4)

print(root.inorderTraversal(root))
print(root.isSymmetric())