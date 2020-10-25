# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 11:38:40 2020

@author: igorm
"""

# 1) Start with a random minion ID n, which is a nonnegative integer of length k in base b
# 2) Define x and y as integers of length k.  x has the digits of n in descending order, and y has the digits of n in ascending order
# 3) Define z = x - y.  Add leading zeros to z to maintain length k if necessary
# 4) Assign n = z to get the next minion ID, and go back to step 2
def solution(n,b):
    x = n
    solutions = [n]
    while (duplications(solutions) == -1):
          x = allgor(x, b)
          solutions.append(x)
    #count index diff b/w two exact solutions
    return len(solutions)-1 - duplications(solutions)

def duplications(slist):
    setList = set()
    for x in slist:
        if x in setList:
            return slist.index(x)
        else:
            setList.add(x)
    return -1

def allgor(n, b):
     k = len(n)
     # convert x & y to base 10 to do subtraction math
     ex = int(sortDe(n), b)
     why = int(sortAs(n), b)
     z = ex - why
     #convert z back to base n
     z = intToBase(z, b)
     if len(z) < k:
         for x in range(k-len(z)):
             z = "0" + z
     return z
     
def intToBase(num, base):
    if num == 0:
        return "0"
    t = []
    while  num:
        t.append(int(num % base))
        num = num // base
    t = [str(z) for z in t]
    t = t[::-1]  #reverses list (same as t.reverse())
    stri = "".join(t)
    return stri

def sortAs(n):
    # copy each digit of n to list
    # run selection sort on list
    # rejoin list elements to form new string return
    sort = [int(x) for x in n]
    for w in range(len(sort)):
        lowi = w
        for y in range(w+1, len(sort)):
            if sort[y] < sort[lowi]:
                lowi = y
        sort[w], sort[lowi] = sort[lowi], sort[w]
    sort = [str(z) for z in sort]
    stri = "".join(sort)
    return stri

def sortDe(n):
    sort = [x for x in sortAs(n)]
    # sort.reverse()
    sort = sort[::-1]
    stri = "".join(sort)
    return stri
    
if __name__ == "__main__":
    print(solution("210022", 3))
    # x = "210111"
    # for z in range(6):
    #     x = allgor(x, 3)
    #     print("x= " + x)
