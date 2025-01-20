from tree import Tree


if __name__ == "__main__":
    n = int(input())
    
    tree = Tree(1)
    for i in range(1,n+1):
        index, left, right = map(int, input().split(' '))
        tree.addNode(index, left, right)