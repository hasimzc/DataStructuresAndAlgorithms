'''
                    Problem Definition
With the range of numbers from 1 to n inclusive, we  can make n! permutations. By labeling them in order starting
from order 1 , you are asked to return the kth permutation.
'''
def kthPermutation(n,k):
    k-=1
    numbers = [i for i in range(1,n+1)]
    kthPermutation = ''
    permutation_amount = permutation(n)
    ct = 1
    while n+1 > ct:
        permutation_amount //= n+1-ct
        digit = k // permutation_amount
        k %= permutation_amount
        kthPermutation += str(numbers[digit])
        numbers.pop(digit)
        ct += 1
    return kthPermutation
def permutation(n):
    result = 1
    ct = 1
    while n > ct:
        ct +=1
        result*=ct
    return result
print(kthPermutation(4,2))
