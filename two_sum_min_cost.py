'''
Find the minimum cost upon adding all members in the array

Input -> [8, 4, 6, 12]
Output -> 58

Explanation:
4 + 6 = 10 => [8, 10, 12] => Cost = 0 + 10 = 10
8 + 10 = 18 => [12, 18] => Cost = 10 + 18 = 28
12 + 18 => [30] => Cost = 28 + 12 = 30

'''

import heapq

def summation(arr):
    heapq.heapify(arr)
    fin_cost = 0
    while (len(arr) > 1):
        inter = heapq.heappop(arr) + heapq.heappop(arr)
        fin_cost += inter
        heapq.heappush(arr, inter)
    
    return (fin_cost)
    
print(summation([8, 4, 6, 12]))
