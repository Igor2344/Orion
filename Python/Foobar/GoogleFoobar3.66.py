# -*- coding: utf-8 -*-
"""
Created on Thu Oct 29 12:53:01 2020

@author: Toast
"""

"""
Can only ADD 1 CELL, REMOVE 1 CELL, DIVIDE n BY 2
return minimum # of operations needed to transform the number to 1

Constraints:
    n is passed in as a string
    n can represent any positive number up to 309 DIGITS long
"""
import math

def solution(n):
    n = long(n)
    if math.log2(n).is_integer(): #number is already a power of 2
        return int(math.log2(n))
    elif math.log2(n-1).is_integer(): #number - 1 is power of 2
        return int(math.log2(n-1) + 1)
    elif math.log2(n+1).is_integer(): #number + 1 is power of 2
        return int(math.log2(n+1) + 1)
    #by here, we either returned OR the number isnt within +/- 1 of a power of 2
    steps = 0
    if n % 2 != 0: #number is odd
        steps += 1 + solution(n-1)
    else:
        steps += 1 + solution(n//2)
    return steps

if __name__ == "__main__":
    print(solution(10))