import sys,time,math

def sieve_of_primes(n):
    if n<=1 :
        return []
    primes = []
    n += 1
    max = int((math.sqrt(n)+1)/2)  
    n = int(n/2)    
    is_primes = []
    pattern = []
    for i in range(2000):
        pattern.append(1)
    if n >= 2000: 
        for i in range(int(n/2000)):
            is_primes += pattern
    else:
        for i in range(n):
            is_primes.append(1)
            
    for p in range(1,max):
        t = (2*p+1)
        x = int(t*t/2)
        if is_primes[p]:
            for j in range(x,n,t):
                is_primes[j] = 0
            primes.append(2*p+1)
    for k in range(max, n):
        if is_primes[k]:
            primes.append(2*k+1)
     
    return [2]+primes
        
n = int(sys.argv[1])            
time_start = time.time()            


print("Total:", len(sieve_of_primes(n)), "primes")

print("Computation time:", round( time.time() - time_start, 3 ) )