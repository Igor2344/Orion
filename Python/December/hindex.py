#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Feb  3 09:42:34 2021

@author: igormiroshnykov
"""

def h_index(size, citations):
    #has index h if atleast h in size has h number of citations
    h = size
    count = 0
    while count < h:
        for x in citations:
            if x >= h:
                count += 1
        if h != count:
            h -= 1
            count = 0
    return h

if __name__ == "__main__":
    print(h_index(5, [4,3,0,1,5]))
    print(h_index(6, [4,5,2,0,6,4]))
    print(h_index(5, [5,5,5,5,5]))