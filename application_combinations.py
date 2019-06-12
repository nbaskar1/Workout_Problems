'''
Given two type of process(foreground and background) in terms of list of list,
where the first element in inner list is the id of the application, whereas
the second element denotes the time it takes to complete the application.

Find the optimal time(max time) to complete the combination of front end and
back end application, when provided with the target.

Input =>

Target = 10,
Foreground = [[1,3],[2,5],[3,7],[4,10]],
Background = [[1,2],[2,3],[3,4],[4,5]]

Output => [[2, 4], [3, 2]]

Explanation =>
FG Id number 2, BG ID number 4 &
FG Id number 3, BG ID number 2

form the optimal combination

'''

import copy

def combinations(target, app1, app2, fin_combo, max_size, app, complement):
    if max_size < target:
        max_size = target
        fin_combo = []
    
    temp_list = []
    for f_app in app1[app]:
        temp_list.append(f_app)
        for b_app in app2[complement]:
            temp_list.append(b_app)
            fin_combo.append(copy.deepcopy(temp_list))
            temp_list.pop(1)
        temp_list.pop()
    
    return (max_size, fin_combo)

def check(target, app1, app2):
    fin_combo = []
    max_size = 0
    
    for app in app1:
        complement = target - app
        if complement in app2:
            max_size, fin_combo = combinations(target, app1, app2, fin_combo, max_size, app, complement)
        
        else:
            if max_size == target:
                continue
            complement -= 1
            while (complement >= 0 and app + complement >= max_size):
                if complement in app2:
                    max_size, fin_combo = combinations(app + complement, app1, app2, fin_combo, max_size, app, complement)
                    break
                complement -= 1
    return (fin_combo)

def optimalUtilization(deviceCapacity, foregroundAppList, backgroundAppList):
    fin_combo = []
    fore_app = {}
    back_app = {}
    target = deviceCapacity
    
    for app in foregroundAppList:
        if not app[1] in fore_app:
            fore_app[app[1]] = []
        fore_app[app[1]].append(app[0])
    
    for app in backgroundAppList:
        if not app[1] in back_app:
            back_app[app[1]] = []
        back_app[app[1]].append(app[0])
    
    if len(fore_app) <= len(back_app):
        fin_combo = check(target, fore_app, back_app)
    else:
        fin_combo = check(target, back_app, fore_app)
        length = len(fin_combo)
        
        for i in range(length):
            fin_combo[i].reverse()
            
    return (fin_combo)

#print (optimalUtilization(10, [[1,3],[2,5],[3,7],[4,10]], [[1,2],[2,3],[3,4],[4,5]]))
#print (optimalUtilization(7, [[1,2],[2,4],[3,6]], [[1,2]]))
#print (optimalUtilization(10, [[1,8],[2,5],[3,6],[4,9]], [[1,7],[2,6],[3,4],[4,10]]))
