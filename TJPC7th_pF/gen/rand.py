import random

def wrand (mn, mx, t):
    lis = [random.randrange(mn,mx+1) for _ in range(abs(t))]
    if t>0:
        return max(lis)
    else:
        return min(lis)