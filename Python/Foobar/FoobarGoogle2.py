# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 10:18:08 2020

@author: igorm
"""

#-- Python cases --
#Input:
#solution.solution([1, 2, 3, 4], 15)
#Output:
#    -1,-1

#Input:
#solution.solution([4, 3, 10, 2, 8], 12)
#Output:
#    2,3

def solution(l,t):
    startIndex = 0
    endIndex = 0
    partial = 0
    # start at beginning of list L, iterate through and add digits as long 
    # as sum < t
    # if sum = t, using last index of added number, return list of two indexes, start and end
    for x in l:
        partial = 0
        for y in range(startIndex, len(l)):
            if partial < t:
                partial += l[y]
                endIndex = y
        if partial < t:
            return [-1,-1]
        if partial == t:
            return [startIndex, endIndex]
        startIndex += 1
        
if __name__ == '__main__':
    solution([1, 2, 3, 4], 15)
    
    solution([4, 3, 10, 2, 8], 12)