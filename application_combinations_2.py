import copy

fg = [20, 30, 40, 70, 60]
bg = [10, 40, 50, 20, 60]
target = 60
maxSum = 0
return_list = []

def remove(arr, target):
    return ([x for x in arr if x < target])

def binarySearch(arr, search):
    if search < arr[0]:
        return (0)
    elif search > arr[len(arr) - 1]:
        return (len(arr) - 1)
        
    lo = 0
    hi = len(arr)
    
    while(lo <= hi):
        mid = (lo + hi) // 2
        #print (mid)
        #break
        
        if arr[mid] == search:
            return (mid)
        elif arr[mid] > search:
            hi = mid - 1
        else:
            lo = mid + 1
        #print (lo, hi, mid)
    
    return (min(lo, hi))

def isMapRequired(arr):
    if len(set(arr)) == len(arr):
        return (False)
    else:
        return (True)

def mapConversion(arr):
    entries = dict()
    
    for value in arr:
        if not value in entries:
            entries[value] = 1
        else:
            entries[value] += 1
    
    return (entries)

def combi(arr1, arr2, entries, dict_flag):
    global maxSum, target
    for value in fg:
        complement = target - value
        print (complement)
        
        if complement > 0:
            idx = binarySearch(bg, complement)
            #print ("Index - " + str(idx))
            total = bg[idx] + value

            if total <= target and total >= maxSum :
                if total > maxSum:
                    return_list.clear()
                    maxSum = total
                temp_list = []
                temp_list.append(bg[idx])
                temp_list.append(value)
                
                if dict_flag:
                    for i in range(0, entries[arr2[idx]]):
                        return_list.append(copy.deepcopy(temp_list))
                else:
                    return_list.append(copy.deepcopy(temp_list))
    
    
fg = remove(fg, target)
bg = remove(bg, target)
fg.sort()
bg.sort()
print (fg)
print (bg)
#print (binarySearch(bg, 50))

if (isMapRequired(bg)):
    entries = mapConversion(bg)
    combi(fg, bg, entries, True)
    
else:
    combi(fg, bg, "", False)

#print (binarySearch(bg, 51))
#print (fg)
print (return_list)
