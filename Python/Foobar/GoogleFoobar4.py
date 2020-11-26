# -*- coding: utf-8 -*-
"""
Created on Thu Nov 19 12:30:08 2020

@author: Toast
"""
"""
Input 2d matrix, each index represents time cost to travel to other array, negative numbers mean you gain time by traveling
Try to save as many bunnies as possible
If several options to save same # of bunnies exist, return the solution with lowest prisoner ID's in sorted order
"""


"""
1st attempt: Look for moves that increment time, always prioritize those moves
If our time_limit is UNDER what we would gain at most from a move, the solution is wrong
"""
def solution(times, time_limit):
    buni = []
    index = 0
    for x in times[0]:
        if x < 0:
            index = x
            
    
    return buni
if __name__ == "__main__":
    times = [
        [0, 2, 2, 2, -1],  # 0 = Start
        [9, 0, 2, 2, -1],  # 1 = Bunny 0
        [9, 3, 0, 2, -1],  # 2 = Bunny 1
        [9, 3, 2, 0, -1],  # 3 = Bunny 2
        [9, 3, 2, 2,  0]  # 4 = Bulkhead
        ]
    