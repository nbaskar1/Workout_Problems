'''
Given a matrix where the row and column contains numbers in sorted order, check wether the given number is present or not
'''

matrix = [[1,2,3,4,17],[5,6,7,8,18],[9,10,11,12,19],[13,14,15,16,20]]

c_matrix = [[1]]

def number_search(matrix, target):
    # Null matrix
    if len(matrix) == 0 or len(matrix[0]) == 0:
        return (False)
    
    # Single row matrix
    if len(matrix) == 1:
        return (binary_search(matrix, target, 0, 0, len(matrix[0])))
    
    # Target Value beyond the extreme ends of the matrix values
    if (matrix[0][0] > target or matrix[len(matrix) - 1][len(matrix[len(matrix) - 1]) - 1] < target):
        return (False)
    else:
        #Binary search on the rows to find the row number
        row_num = col_binary_search(matrix, target, 0, 0, len(matrix) - 1)
        if row_num == -1:
            return (True)
        # Binary search on the concerned row to find the element's presence
        return (binary_search(matrix, target, row_num, 0, len(matrix[row_num])))

# Regular binary search
def binary_search(matrix, target, row, low, high):
    while (low <= high):
        middle = (low + high) // 2
        
        if matrix[row][middle] == target:
            return (True)
        else:
            if matrix[row][middle] > target:
                return (binary_search(matrix, target, row, low, middle - 1))
            else:
                return (binary_search(matrix, target, row, middle + 1, high))
    
    return (False)

# Modified binary search on the rows
def col_binary_search(matrix, target, col, low, high):
    while (low <= high):
        middle = (low + high) // 2
        
        if matrix[middle][col] == target:
            return (-1)
        elif matrix[middle][col] < target and middle == high:
            return (middle)
        elif matrix[middle][col] < target and matrix[middle + 1][col] > target:
            return (middle)
        else:
            if matrix[middle][col] > target:
                return (col_binary_search(matrix, target, col, low, middle - 1))
            else:
                return (col_binary_search(matrix, target, col, middle + 1, high))
