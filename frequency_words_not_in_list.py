#Given a string and a list of excluded words, find out the maximum occurences of words not present in the excluded list

#Input => 
#lit = "Jack and Jill went to the market to buy bread and cheese. Cheese is Jack's and Jill's favorite food"
#exclude = ["and", "he", "the", "to", "is", "Jack", "Jill"]

#Output => ["cheese", "s"]

import re

lit = "Jack and Jill went to the market to buy bread and cheese. Cheese is Jack's and Jill's favorite food"
exclude = ["and", "he", "the", "to", "is", "Jack", "Jill"]

def desensitize(lis):
    length = len(lis)
    
    for idx in range(length):
        lis[idx] = lis[idx].lower()
    
    return (lis)

def freq(lit, exclude):
    exclude = desensitize(exclude)
    exclude_set = set(exclude)
        
    entries = dict()
    lit_list = re.compile("[^A-Za-z]").split(lit)
    lit_list = desensitize(lit_list)
    
    for word in lit_list:
        if len(word) < 1:
            continue
        
        if not word in exclude_set: 
            if not word in entries:
                entries[word] = 1
            else:
                entries[word] += 1
    
    keys = entries.keys()
    
    ret_list = list()
    max_freq = 0
    
    for key in keys:
        if entries[key] == max_freq:
            ret_list.append(key)
        elif entries[key] > max_freq:
            ret_list.clear()
            ret_list.append(key)
            max_freq = entries[key]
    
    return (ret_list)
    
    

print (freq(lit, exclude))
