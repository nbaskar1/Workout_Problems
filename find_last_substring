#Given a string, find all substrings possible and print the alphabetically large last substring.

#Input => "abcdd"
#Output => "dd"

string = "abcdd"

def findLastSubstring(string):
    max_idx = 0
    max_val = 0
    for idx, char in enumerate(string):
        if ord(char) > max_val:
            max_val = ord(char)
            max_idx = idx
    
    return (string[max_idx:])

print (findLastSubstring(string))
