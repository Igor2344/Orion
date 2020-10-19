def sevenish(n):
    # either a power of 7 or the sum of unique powers of 7
    # sevenish numvers: 1, 7, 8, 49, 50, 56, 57, 343 ...
    l = []
    p = 0
    pos = 0
    while len(l) < n:
        l.append(7**p)
        pos = len(l)-1
        for x in range(len(l)-1):
            l.append(l[x] + l[pos])
        p += 1
    return l[n-1]

if __name__ == "__main__":
    for x in range(1, 11):
        print(sevenish(x))