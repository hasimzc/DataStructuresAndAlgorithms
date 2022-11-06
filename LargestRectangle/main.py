'''
                    Problem definition
Given an array heights that contains the height of each bar in the histogram, and we are asked to return the area of
the largest rectangle in the histogram. Note that eachbar has a width of 1.
'''
height = list(map(int,input().split()))
maximum = 0
left = 0
right = len(height) -1
while left < right:
    maximum = max((right-left) * min(height[left], height[right]),maximum)
    if height[left] <height[right]:
        left+=1
    else:
        right-=1
print(maximum)