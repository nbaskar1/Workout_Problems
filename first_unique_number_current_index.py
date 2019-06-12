'''
From the given array, find the unique number up until the given index

Input => [2, 3, 1, 2, 1, 3, 5]
Output => [2, 2, 2, 3, 3, "", 5]

'''

from collections import OrderedDict

unique = OrderedDict()

arr = [2, 3, 1, 2, 1, 3, 5]
uni = []

for num in arr:
    print (unique)
    if num in unique:
        del unique[num]
    else:
        unique[num] = 0
    
    if len(unique) > 0:
        uni.append(next(iter(unique)))
    else:
        uni.append("")

print (uni)
