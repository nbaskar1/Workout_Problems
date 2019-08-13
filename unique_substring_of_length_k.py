# Find all unique substring of length K
# Input => "awaglknagawunagwkwagl"
# Output => ['wagl', 'aglk', 'glkn', 'lkna', 'knag', 'gawu', 'awun', 'wuna', 'unag', 'nagw', 'agwk', 'kwag']

string = "awaglknagawunagwkwagl"
#string = "abcd"

def words(string, size):
    length = len(string)
    arr = list()
    ret = set()
    ret_list = list()
    
    for i in range(26):
        arr.append(0)
    
    head = 0
    tail = 0
    buf = ""
    flag = False
    
    while (tail < length):
        if flag:
            arr[ord(string[head]) - ord('a')] -= 1
            buf = buf[1:]
            
            if (arr[ord(string[head]) - ord('a')]) == 1:
                flag = False
            head += 1
        else:
            if (arr[ord(string[tail]) - ord('a')] != 0):
                flag = True
            
            buf += string[tail]
            arr[ord(string[tail]) - ord('a')] += 1
            tail += 1
            
            if flag:
                continue
            
            if (tail - head == size):
                if not buf in ret:
                    ret_list.append(buf)
                ret.add(buf)
                arr[ord(string[head]) - ord('a')] -= 1
                head += 1
                buf = buf[1:]
    
    return (ret_list)

print (words(string, 4))
        
