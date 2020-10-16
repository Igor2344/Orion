# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 13:29:07 2020

@author: igorm
"""
# primes: 2,3,5,7,11,13,17,19,23,29
def solution(i):
    #using i to create a prime number string of i+5 characters long
    prim = ""
    j = 2
    while len(prim) < i+5:
        if isprime(j):
            prim += str(j)
        j += 1
    #grab numbers at index i and the next 4 digits, assign to ID string
    eyedee = ""
    for x in range(i, i+5):
        eyedee += prim[x]
    #return id string
    return eyedee
    
def isprime(n):
    #what is a prime number? only divisible by itself AND 1
    # in comp math? from 2 to number, number/iterator must be 0
    for x in range(2,n+1): #if n = 5, range needs to go from 2 to n-1 = 4 
        if n%x == 0 and n != x:
            return False
    return True
    

if __name__ == '__main__':
    print(solution(5))
    print(solution(3))
    print(solution(0))