import random

def wrand (mn, mx, t):
    lis = [random.randrange(mn,mx) for _ in range(abs(t))]
    if t>0:
        return max(lis)
    else:
        return min(lis)

n = random.randrange(1,1e5)
k = wrand(1,1e16,10)
print(f'{n} {k}')
for i in range(n):
    print(wrand(1,1e8,-10), end='') 
    if i < n:
        print(' ', end='')
    else:
        print()
