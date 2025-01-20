

class Tree:
    def __init__(self, index, left=None, right=None):
        self.index = index
        self.left = left
        self.right = right

    def addNode(self, index, left, right):
        if self.index == index:
            if left != -1:
                self.left = Tree(left)
            if right != -1:
                self.right = Tree(right)
        else:
            if self.left is not None:
                self.left.addNode(index, left, right)
            if self.right is not None:
                self.right.addNode(index, left, right)


def getHeight(tree):

    if tree.left == None and tree.right == None: 
        return 1
    else :
        h1 = getHeight(tree.left) if tree.left is not None else 0
        h2 = getHeight(tree.right) if tree.right is not None else 0

        return max(h1, h2) + 1




if __name__ == "__main__":
    n = int(input())

    tree = Tree(1)
    for i in range(1, n):
        index, left, right = map(int, input().split())
        tree.addNode(index, left, right)


    print(getHeight(tree))