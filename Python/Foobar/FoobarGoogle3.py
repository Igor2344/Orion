# -*- coding: utf-8 -*-
"""
Created on Mon Oct 19 21:55:10 2020

@author: igorm
"""

#maze of 2d matrix, 0 = passable, 1 = wall
# function to turn 1 wall into passable
# wall removal function may be unused

#only move up down left right, no diagonals
#height & width can be 2 to 20
#map always solvable, but may require removing wall

#to solve maze:
    #rewrite all adjacent steps from origion as +1 (unless its a wall)
    #keep adding outward in every direction
    #when a number is written to the finish spot, that is the optimal path length
        #does not consider needing wall replaced
        #what is need wall remove condition?
            #if all spots written on that arent walls but exit is still unwritten
        #where to choose a wall?
        
# start always at [0,0]
# end is always at [length - 1, width -1]

# def solution(n): #input is 2d list of coordinates
#     z = n
#     move = 1
#     while(z[len(z)-1][len(z[0])-1] == 0): #while the endpoint has no path length
#         #write move to each adjacent non wall spot
#     return move
    

def demolish(coord, n): #replaces wall with empty space in 2d list n
    x = coord[0]
    y = coord[1]
    n[x][y] = 0
    return n

if __name__ == "__main__":
    n = [
        [0,0,0],
        [0,0,0]
        ]
    print(n)
    i = 1
    for x in range(3):
        for y in range(3):
            n[x][y] = i
            i += 1
    print(n)