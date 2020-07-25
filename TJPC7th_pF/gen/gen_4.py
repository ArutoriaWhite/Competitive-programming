from rand import wrand

n = wrand(2,100000000,-10)
m = wrand(2,1000,100)

if n < m:
    n,m = m,n

print(f'{n} {m}')

st = set()
while len(st) < m:
    st.add( wrand(1,n,1) )
lis = [x for x in st]
for x in sorted(lis):
    print(f'{x} {wrand(0,1,1)}')