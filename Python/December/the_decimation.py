# -*- coding: utf-8 -*-
"""
Created on Mon Dec 14 12:07:39 2020

@author: Toast
"""

#While list ISNT sorted, remove half from the list

def isSorted(tlist): #checks if each preceding value in a list is less, if so, list is not sorted
    for x in range(len(tlist)-1):
        for y in range(x+1,len(tlist)):
            if tlist[y] < tlist[x]:
                return False
    return True

def decimate(alist):
    while isSorted(alist) == False or len(alist) == 1:
        #remove every other value in a list
        alist.remove(alist[len(alist)//2])
            
if __name__ == "__main__":
    ourlist = [1,2,5,4,5]
    decimate(ourlist)
    print(ourlist)
    