# -*- coding: utf-8 -*-
"""
Created on Sun Oct 18 23:44:23 2020

@author: igorm
"""

def credit(numb):
    number = ""
    number = numb[::-1]
    s1 = 0
    s2 = 0
    for x in range(len(number)):
        if x % 2 == 0:
            s1 += int(number[x])
        else:
            if int(number[x]) * 2 > 9:
                s2 += ((int(number[x]) * 2) % 10) + ((int(number[x]) * 2) // 10)
            else:
                s2 += (int(number[x]) * 2) % 10
    return (s1 + s2)  % 10 == 0

if __name__ == "__main__":
    print(credit("49927398716"))