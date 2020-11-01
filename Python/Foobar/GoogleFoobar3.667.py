# -*- coding: utf-8 -*-
"""
Created on Sat Oct 31 22:44:47 2020

@author: Toast
"""

def solution(n):
  n = long(n)
  x = long(1)
  steps = 0
  while(x < n):
    x *= 2
    steps += 1
  #check if x is within 1 of n
  if n + 1 == x or n - 1 == x/2:
    return steps + 1
  else:
    if n % 2 == 0:
      n = n/2
      x = x/2
      steps -= 1
      if n + 1 == x or n - 1 == x:
        return steps + 1
      else:
        steps = steps + solution(n)
    else:
      n = (n-1)/2
      x = x/2
      steps = (steps - 1) + solution(n)
  return steps

  if __name__ == "__main__":
    print(solution(10))