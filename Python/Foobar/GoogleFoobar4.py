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

"""
If there is a negative cycle, return list of all bunnies in order (we can save all of them)
use bellman-ford algo to detect negative cycles & solve problem
"""
def solution(times, time_limit):
    buni = []
    index = 0
    for x in times[0]:
        if x < 0:
            index = x
            
    
    return buni

def bfa(vertexes, edges): # source is always at index 0
    #edges are represented as a list of lists such as (1,2,w) meaning the edge path from vertex 1 to 2 with weight w

    #set all distances to infinity (idk how yet)
    #vertex relaxation must run vertexes-1 number of times
    #go thru all paths and check IF current path time is < previous path, then replace distance
    #after vertex-1 runs, run one more time, if any changes are made, there is a negative cycle
    distance = []
    predecesor = []
    
    for v in vertexes:
        distance[v] = #infinity
        predecessor[v] = None
        
    distance[0] = 0
    
    #edge relaxation (vertexes-1 iterations)
    for x in range(vertexes.len()-1):
        for y in edges:
            if distance[y[0]] + y[2] < distance[y[1]]:
                distance[y[1]] = distance[y[0]] + y[2]
                predecessor[y[1]] = y[0]
              
    #test for negative cycles after relaxation completion
    for y in edges:
            if distance[y[0]] + y[2] < distance[y[1]]:
                #then we know there is a negative cycle
    
    
if __name__ == "__main__":
    times = [
        [0, 2, 2, 2, -1],  # 0 = Start
        [9, 0, 2, 2, -1],  # 1 = Bunny 0
        [9, 3, 0, 2, -1],  # 2 = Bunny 1
        [9, 3, 2, 0, -1],  # 3 = Bunny 2
        [9, 3, 2, 2,  0]  # 4 = Bulkhead
        ]
    