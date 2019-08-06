Given a binary tree, print the levels in a zig zag fashion

import copy

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def listPrinter(level, leftToRight):
    string = ""
    
    if leftToRight:
        for root in level:
            if not root is None:
                string += " " + str(root.value)
    
    else:
        length = len(level) - 1
        for idx in range(length, -1, -1):
            if not level[idx] is None:
                string += " " + str(level[idx].value)
    
    print (string)

def zigZagPrint(root, leftToRight):
    if root is None:
        print (None)
        return
    
    curr_level = list()
    next_level = list()
    stop_flag = False
    
    curr_level.append(root)
    
    while not stop_flag:
        listPrinter(curr_level, leftToRight)
        stop_flag = True
        while curr_level:
            curr_root = curr_level.pop(0)
            
            if curr_root is None:
                continue
            else:
                next_level.append(curr_root.left)
                next_level.append(curr_root.right)
                
                if stop_flag and (curr_root.left != None or curr_root.right != None): 
                    stop_flag = False
        
        curr_level = copy.deepcopy(next_level)
        next_level.clear()
        leftToRight = not leftToRight
    

root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)

zigZagPrint(root, True)
#print (root.value)
