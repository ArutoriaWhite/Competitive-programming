import sys,time,math

def sieve_of_primes(n):
    if n<=1 :
        return []

    primes = []
    is_primes = []
#    pattern = [1 for i in range(0,2000)]
    pattern = []
    for i in range(2000):
        pattern.append(1)
    
    if n >= 2000: 
        for i in range(int(n/2000)):
            is_primes += pattern
    else:
        for i in range(n):
            is_primes.append(1)

    mx = int(math.sqrt(n))+1
    for i in range(2,int(math.sqrt(n))+1):
        if is_primes[i]:
            x = i*i
            for j in range(x,n):
                is_primes[j] = 0
    return primes
        
n = 5000000
time_start = time.time()            


print("Total:", len(sieve_of_primes(n)), "primes")

print("Computation time:", round( time.time() - time_start, 3 ) )