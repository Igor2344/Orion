# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 10:52:50 2020

@author: igorm
"""

# find triples within a list of integers
# list size from 2 and 2000 inclusive
# elements between 1 and 999999 inclusive

#what are triples?
    # a tuple [x,y,z] where x divides y and y divides z
    # example [1,2,4] or [1,2,6]
    # tuples must be written in order based on list indices
    # tuples may not exist, if so, return 0
    
# ideas for going about locating tuples
    # is the list already sorted from least to greatest?
    # parse list from end to start, check division using modulus == 0
    # if two match, begin third loop to check for 3rd triple (smallest one)
    # if all 3 exist, save as unique list
    # end with returning # of unique lists
    
def solution(l):
    tripl = 0
    for x in range(len(l)-1, 1, -1): #start from length - 1, end at x = 2, using steps of -1
        for y in range(x-1, 0, -1):
            if l[x] % l[y] == 0: # we have 2/3 tuples
                for z in range(y-1, -1, -1):
                    if l[y] % l[z] == 0: # 3/3 tuples
                        tripl += 1
    return tripl

# very inefficient code, needs reworking