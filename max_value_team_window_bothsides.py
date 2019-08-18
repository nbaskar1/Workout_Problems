# Given an array of team member values, team members required and the window size, get the total tally of the max value in the window
# size on both the sides of the array, and roll the window towards each other until the remaining team size becomes zero
# If the front and the back window overlap completely at any point of time return the sum of the array
# If the team members required is more than the length of the array, return the sum of the array

# arr = [10, 20, 5, 18, 16, 12, 2, 11, 1, 13, 19]
# m = 3
# team = 5

# Output -> 79

# Explanation -> 20 + 19 + 18 + 16 + 13
# [10, 20, 05], [01, 13, 19]
# [10, 05, 18], [01, 13, 19]
# [10, 05, 18], [11, 01, 13]
# [10, 05, 16], [11, 01, 13]
# [10, 05, 12], [11, 01, 13]

import heapq

arr = [10, 20, 5, 18, 16, 12, 2, 11, 1, 13, 19]
#arr = [10, 9, 8, 1, 2]
m = 3
team = 5

def modifyData(arr, length):
    for idx in range(length):
        arr[idx] *= -1
    
    return (arr)
    
def addData(heap, arr, indexSet, start, stop, flag):
    for idx in range(start, stop):
        if not idx in indexSet:
            heap.append((arr[idx], idx, flag))
            indexSet.add(idx)
    return (heap, indexSet)

def teamCombo(arr, m , team):
    length = len(arr)
    
    if (team >= length or m >= length or length - team < m):
        return (sum(arr))
    
    arr = modifyData(arr, length)
    heap = list()
    frontTail = m
    backTail = length - m - 1
    indexSet = set()
    
    if team > 0:
        heap, indexSet = addData(heap, arr, indexSet, 0, m, True)
        heap, indexSet = addData(heap, arr, indexSet, length - 1 - m, length - 1, False)
        
    heapq.heapify(heap)
    popVal = heapq.heappop(heap)
    finSum = popVal[0] * -1
    team -= 1
    
    while (team > 0):
        if backTail > frontTail + 1:
            if not popVal[2] and not backTail in indexSet:
                heapq.heappush(heap, (arr[backTail], backTail, False))
                indexSet.add(backTail)
                backTail -= 1
            elif popVal[2] and not frontTail in indexSet:
                heapq.heappush(heap, (arr[frontTail], frontTail, True))
                indexSet.add(frontTail)
                frontTail += 1
            
        popVal = heapq.heappop(heap)
        #print (popVal[0] * -1)
        finSum += popVal[0] * -1
        team -= 1
        
    return (finSum)

print (teamCombo(arr, m, team))
