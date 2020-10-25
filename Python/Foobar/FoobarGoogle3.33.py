# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 10:52:50 2020

@author: igorm
"""

# find triples within a list of integers
# list size from 2 and 2000 inclusive
# elements between 1 and 999,999 inclusive

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
    
# if all elements in list l are the same, how many triples are there?
# for list n = [1,1,1,1,1] there are 5 1s
# 1+1+1  +  1+1  +  1  + 1+1 + 1   +1  = 3 + 2 + 1 + 2 + 1 + 1
# this is the same as adding decreasing triangle numbers
# 3 + 2 + 1 = 3(4)/2 = 6 or n(n+1)/2
# starting number is len(list) - 2   

# code passes 4/5 google foobar tests, 1 hidden test is failed
# what failed more tests?
    # assuming list isnt sorted
    # counting only unique triples
# the problem? [1,1,2,4]
# expect 3, get 4. we double count [1,1,4] when


#what if list is only prime numbers? expect return 0 unless duplicates
    
def solution(l):
    tripl = 0
    if allFactors(l):
        for x in range(len(l) - 2, 0, -1):
            tripl += (x)*(x+1)//2
        return tripl
    if allPrime(l):
        pset = {i for i in l}
        if len(pset) != len(l): # then we have duplicate primes
            # how do we count triples of duplicate primes without using the same triple loop?
            for i in range(2, len(l)):
                if l[i] == l[i-1]:
                    for j in range(i-1):
                        if l[i] % l[j] == 0:
                            tripl += 1
            return tripl
        else:
            return 0
    for x in range(len(l)-1, 1, -1): #start from length - 1, end at x = 2, using steps of -1
        for y in range(x-1, 0, -1):
            if l[x] % l[y] == 0: # we have 2/3 tuples
                for z in range(y-1, -1, -1):
                    if l[y] % l[z] == 0: # 3/3 tuples
                            tripl += 1
    return tripl

def allFactors(l): #if all numbers in list are factors
    for x in range(1, len(l)):
        if l[x] % l[x-1] != 0:
            return False
    return True

def allPrime(l): # if all numbers in list are primes (no factors)
    for x in range(1, len(l)):
        if not isPrime(l[x]):
            return False
    return True

def isPrime(x):
    if x == 1 or x == 2:
        return True
    else:
        for i in range(2, x): # start at 2 to x-1, if none divide without remainder, then its prime
            if x % i == 0:
                return False
        return True
if __name__ == "__main__":
    n = []
    # for x in range(4):
    #     n[len(n):] = [1]
    n = [1,2,3,7,7,7,11]
    print(solution(n))