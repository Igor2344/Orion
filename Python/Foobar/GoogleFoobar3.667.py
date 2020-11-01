# -*- coding: utf-8 -*-
"""
Created on Sat Oct 31 22:44:47 2020

@author: Toast
"""

def oldSolution(n):
  n = long(n)
  x = [1L]
  step = 0
  while x[len(x)-1] < n:
    x.append(x[len(x)-1] * 2)
  while len(x) > 2:
    if n == x[len(x)-1] or n - 1 == x[len(x)-2]:
      return len(x)-1 + step
    elif n + 1 == x[len(x)-1]:
      return len(x) + step
    else:
      x.pop()
      if n % 2 == 0:
        n = n / 2
        step += 1
      else: # decide whether to add 1 or sub 1
        if (n+1)&n > (n-1)&(n-2):
          n = (n - 1) / 2
          step += 2
        else:
          n = (n + 1) / 2
          step += 2
  # n is 3L, 2L, or 1L, return 2 1 or 0
  return int(n) - 1 + step

def test2():
  for x in range(1L,100L):
    if oldSolution(x) != solution(x):
      print ("False",x)

def solution(n):
    n = long(n)
    steps = 0
    while(n != 1):
        if n % 2 == 0:
            n /= 2
        elif n == 3 or (n+1) & n > ((n-1) & (n-2)):
            n -= 1
        else:
            n += 1
        steps += 1
    return steps

if __name__ == "__main__":
  test2()