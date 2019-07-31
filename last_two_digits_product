# Compute the product of all numbers in the given array and return the last two numbers of the final product
# Input => [1234, 1235, 1236]
# Output => 40


import math

val = [1234, 1235, 1236]

def mult(num, num2):
    num1 = int(num)
    fin_string = ""
    result = (num1 % 10) * (num2 % 10)
    fin_string = str(result % 10)
    result = ((math.floor((num1 % 100) / 10)) * (num2 % 10)) + ((num1 % 10) * (math.floor((num2 % 100) / 10))) + (math.floor((result % 100) / 10))
    fin_string = str(result) + fin_string
    
    return (fin_string[-2:])

def prod(arr):
    length = len(arr)
    result = mult(arr[0], arr[1])
    
    if length > 2:
        for ind in range(2, length):
            result = mult(result, arr[ind])
    
    return (result)

print(prod(val))
