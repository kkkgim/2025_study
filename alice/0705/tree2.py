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

def preorder(tree):
    if tree == None:
        return []
    return [tree.index] + preorder(tree.left) + preorder(tree.right)


def inorder(tree):
    if tree == None :
        return []
    return inorder(tree.left) + [tree.index] + inorder(tree.right)


def postorder(tree):
    if tree == None :
        return []
    return postorder(tree.left) + postorder(tree.right) + [tree.index] 


if __name__ == "__main__":
    n = int(input())
    
    tree = Tree(1)
    for i in range(1,n+1):
        index, left, right = map(int, input().split(' '))
        tree.addNode(index, left, right)
    
    print(preorder(tree))
    print(inorder(tree))
    print(postorder(tree))
    print(' '.join(map(str,inorder(tree))))
    # print(' '.join(postorder(tree)))

