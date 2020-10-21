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
    #rewrite all adjacent steps from origin as +1 (unless its a wall)
    #keep adding outward in every direction
    #when a number is written to the finish spot, that is the optimal path length
        #does not consider needing wall replaced
        #what is need wall remove condition?
            #if all spots written on that arent walls but exit is still unwritten
        #where to choose a wall?
        
# start always at [0,0]
# end is always at [length - 1, width -1]

# ROW x COLUMN
# adjacent spots from n[x][y]: how do we know if any of the spots are nonexistent? if x,y = 0. there is no up or left
    # up: n[x-1][y]
    # down: n[x+1][y]
    # left: n[x][y-1]
    # right: n[x][y+1]

def solution(n): #input is 2d list of coordinates
    ncopy = [[]]
    ncopy = copyList(ncopy, n)
    minMove = mazeRun(n)
    for x in range(len(n)):
        for y in range(len(n[0])):
            if n[x][y] == 1:
                n = copyList(n, ncopy)
                n = demolish([x,y], n)
                if mazeRun(n) < minMove:
                    minMove = mazeRun(n)
    return minMove

def copyList(a, b):
    a = [[0 for x in range(len(b[0]))] for y in range(len(b))]
    for x in range(len(b)):
        for y in range(len(b[0])):
            a[x][y] = b[x][y]
    return a
    
def mazeRun(n):
    z = [[0 for x in range(len(n[0]))] for y in range(len(n))]
    z[0][0] = 1
    move = 1
    while(z[len(z)-1][len(z[0])-1] == 0 and move < len(n) * len(n[0])): #while the endpoint has no path length (is 0)
        #write move to each adjacent non wall spot
        for x in range(len(z)):
            for y in range(len(z[0])):
                if z[x][y] == move:
                    if x > 0 and z[x-1][y] == 0 and n[x-1][y] == 0:
                        z[x-1][y] = move + 1
                    if x < len(z) - 1 and z[x+1][y] == 0 and n[x+1][y] == 0:
                        z[x+1][y] = move + 1
                    if y > 0 and z[x][y-1] == 0 and n[x][y-1] == 0:
                        z[x][y-1] = move + 1
                    if y < len(z[0]) - 1 and z[x][y+1] == 0 and n[x][y+1] == 0:
                        z[x][y+1] = move + 1
        move += 1
    return move

def demolish(coord, n): #replaces wall with empty space in 2d list n
    x = coord[0]
    y = coord[1]
    n[x][y] = 0
    return n

if __name__ == "__main__":
    #what if start or end is 1?
    n = [
        [0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
        [0, 1, 1, 1, 1, 1, 1, 0, 1, 1],
        [0, 0, 1, 1, 0, 0, 0, 0, 1, 1],
        [1, 0, 1, 1, 0, 1, 1, 0, 0, 0],
        [1, 0, 1, 1, 0, 1, 1, 0, 0, 1],
        [1, 0, 1, 1, 0, 1, 1, 0, 0, 1],
        [1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1, 0, 1, 1],
        [1, 1, 1, 1, 1, 1, 0, 0, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 0, 0, 0]
    ]
    print(solution(n))