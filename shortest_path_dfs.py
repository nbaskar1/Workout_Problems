'''
Find the minimum distance path between [0, 0] and location of 9 in the given
two dimensional matrix

Input =>
[1, 0, 0;
 1, 9, 1;
 1, 1, 1;]

Output => 2

'''

import copy

min_dist = 999999999

def wrapper(x, y, distance, matrix, visit, x_size, y_size):
    global min_dist
    visited = copy.deepcopy(visit)
    
    if x < 0 or y < 0 or x >= x_size or y >= y_size:
        return (distance)
    elif matrix[x][y] == 9:
        if distance < min_dist:
            min_dist = distance
        return (distance + 1)
    elif matrix[x][y] == 0 or visited[x][y] == 1:
        return (distance)
    else:
        distance += 1
        visited[x][y] = 1
        
        wrapper(x + 1, y, distance, matrix, visited, x_size, y_size)
        wrapper(x, y + 1, distance, matrix, visited, x_size, y_size)
        wrapper(x, y - 1, distance, matrix, visited, x_size, y_size)
        wrapper(x - 1, y, distance, matrix, visited, x_size, y_size)
        return (distance)
    
def traversal(matrix):
    x_size = len(matrix)
    y_size = len(matrix[0])
    visited = [[0 for _ in range(y_size)] for _ in range(x_size)]
    
    wrapper(0, 0, 0, matrix, visited, x_size, y_size)
    return (min_dist)

print (traversal([[1,0,0,0],[1,1,9,1],[1,1,1,1]]))
