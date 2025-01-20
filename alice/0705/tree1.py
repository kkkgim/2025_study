'''
preorder, inorder, postorder 함수를 구현하세요.
'''

def preorder(tree) :
    '''
    tree를 전위순회 하여 리스트로 반환하는 함수를 작성하세요.
    '''
    if tree == None :
        return []
    return [tree.index] + preorder(tree.left) + preorder(tree.right)

    return result

def inorder(tree) :
    '''
    tree를 중위순회 하여 리스트로 반환하는 함수를 작성하세요.
    '''
    if tree == None :
        return []
    return inorder(tree.left) + [tree.index] + inorder(tree.right)


def postorder(tree) :
    '''
    tree를 후위순회 하여 리스트로 반환하는 함수를 작성하세요.
    '''

    if tree == None :
        return []
    return postorder(tree.left) + postorder(tree.right) + [tree.index] 

class Tree:
    def __init__(self, index, left=None, right=None):
        self.index = index
        self.left = left 
        self.right = right 


if __name__ == "__main__":
    n = int(input())
    # 트리 초기화 
    trees = {i: Tree(i) for i in range(1, n + 1)}
    
    for i in range(1,n+1):
        index, left, right = map(int,input().split(' '))

        if left != -1:
            trees[i].left = trees[left]
        if right != -1:
            trees[i].right = trees[right]

    tree = trees[1]

    print(preorder(tree))
    print(inorder(tree))
    print(postorder(tree))

        
        
