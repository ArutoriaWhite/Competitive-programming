from rand import wrand

n = wrand(3,100000000,1)
m = 2
if n < m:
    n,m = m,n

print(f'{n} {m}')

st = set()
while len(st) < m:
    st.add( wrand(1,n,1) )
lis = [x for x in st]
for x in sorted(lis):
    print(f'{x} {wrand(0,1,1)}')