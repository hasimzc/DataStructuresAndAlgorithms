'''
                            Problem definition
Given an array of integers arr and an integer k, find the k th largest element.                         
'''
import heapq
def kth_largest(arr,k):
    array = [-i for i in arr]
    heapq.heapify(array)
    for i in range(k-1):
        heapq.heappop(array)
    return - heapq.heappop(array)
print(kth_largest([3,5,2,4,1,6,4],2))
