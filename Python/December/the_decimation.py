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
    while !isSorted(alist) or len(alist) == 1:
        #remove every other value in a list
        for x in range(len(alist)):
            alist.remove(alist[x])
            x+=1