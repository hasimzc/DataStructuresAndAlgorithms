liste = list(map(int,input().split()))
def binarySearchForFirstIndex(target,liste,index):
    n = len(liste)
    if n == 1:
        if liste[0] == target:
            return index-1
        else:
            return index
    mid = n//2
    number = liste[mid]
    if number == target:
       return binarySearchForFirstIndex(target,liste[:mid],mid)
    else:
        if target > number:
            return binarySearchForFirstIndex(target,liste[mid:],index)
        else:
            return binarySearchForFirstIndex(target,liste[:mid],index)
def binarySearchForLastIndex(target,liste,index):
    n = len(liste)
    if n == 1:
        if liste[0] == target:
            return index+1
        else:
            return index
    mid = (n)//2
    number = liste[mid]
    if number == target:
       return binarySearchForLastIndex(target,liste[mid:],mid+index)
    else:
        if target > number:
            return binarySearchForLastIndex(target,liste[mid:],index)
        else:
            return binarySearchForLastIndex(target,liste[:mid],index)
a = binarySearchForFirstIndex(3,liste,-1)
b = binarySearchForLastIndex(3,liste,-1)
print(a,b)