# -*- coding: utf-8 -*-
"""
Created on Sat Oct 24 22:48:14 2020

@author: igorm
"""    
# def solution(l):
#     tripl = 0
#     if allFactors(l):
#         for x in range(len(l) - 2, 0, -1):
#             tripl += (x)*(x+1)//2
#         return tripl
#     if allPrime(l):
#         pset = {i for i in l} # set with only unique values
#         if len(pset) != len(l): # then we have duplicate primes
#             # how do we count triples of duplicate primes without using the same triple loop?
#             for i in range(2, len(l)):
#                 if l[i] == l[i-1]:
#                     for j in range(i-1, 0, -1):
#                         if l[i] % l[j] == 0:
#                             for k in range(j-1, -1, -1):
#                                 if l[j] % l[k] == 0:
#                                     tripl += 1
#             return tripl
#         else:
#             return 0
#     for x in range(len(l)-1, 1, -1): #start from length - 1, end at x = 2, using steps of -1
#         for y in range(x-1, 0, -1):
#             if l[x] % l[y] == 0: # we have 2/3 tuples
#                 for z in range(y-1, -1, -1):
#                     if l[y] % l[z] == 0: # 3/3 tuples
#                             tripl += 1
#     return tripl

# def allFactors(l): #if all numbers in list are factors
#     for x in range(1, len(l)):
#         if l[x] % l[x-1] != 0:
#             return False
#     return True

# def allPrime(l): # if all numbers in list are primes (no factors)
#     for x in range(1, len(l)):
#         if not isPrime(l[x]):
#             return False
#     return True

# def isPrime(x):
#     if x == 1:
#         return False
#     elif x == 2:
#         return True
#     else:
#         for i in range(2, x): # start at 2 to x-1, if none divide without remainder, then its prime
#             if x % i == 0:
#                 return False
#         return True
def solution(l):
    multip = [0] * len(l) #creates list with len(l) and fills with 0s
    tripl = 0
    for i in range(len(l)):
        for j in range(i):
            if l[i] % l[j] == 0:
                multip[i] += + 1 # adds 1 for each multiple into c list
                tripl += multip[j] # once two numbers divide, checks c list for multiples to numbers before it, adds to count
    return tripl

if __name__ == "__main__":
    # n = []
    # for x in range(2000):
    #     n[len(n):] = [1]
    # print(solution(n))
    # n = [1,2,3,7,7,7,11]
    print(solution([1,1,1]) == 1)
    print(solution([1,2,3,4,5,6]) == 3)
    print('\n')
    print(solution([1,1,1,1]) == 4)
    print(solution([1,1,1,1,1]) == 10)
    print(solution([1,1,1,1,1,1]) == 20)
    print(solution([1,1,1,1,1,1,1]) == 35)
    print(solution([1,2]) == 0)
    print(solution([2,4]) == 0)
    print(solution([1,1,1,1]) == 4)
    print(solution([1,1,2,2]) == 4)
    print(solution([2,3,7,11]) == 0)
    print(solution([2,3,7,11,13]) == 0)
    print(solution([2,3,7,11,11]) == 0)
    print(solution([2,3,7,11,11,11]) == 1)
    print(solution([1,2,3,7,7,7,11]) == 4)
    print(solution([1,1,2,2,2,3]) == 11)
    print(solution([2,2,2,2,4,4,5,6,8,8,8]) == 90)
    print(solution([4,7,14]) == 0)
    print(solution([4, 21, 7, 14, 8, 56, 56, 42]) == 9)
    print(solution([4, 21, 7, 14, 56, 8, 56, 4, 42]) == 7)