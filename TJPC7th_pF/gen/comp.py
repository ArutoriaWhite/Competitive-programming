import os

gen = 'gen'
sol = '../solution/n2'
sol2 = '../solution/nlogn'
taskNum = 100000
os.system(f'g++ -std=c++14 -o {sol}.out {sol}.cpp')
os.system(f'g++ -std=c++14 -o {sol2}.out {sol2}.cpp')

for cnt in range(taskNum):
    os.system(f'python3 {gen}.py > cmp.in')
    os.system(f'./{sol}.out < cmp.in > comp1.out')
    os.system(f'./{sol2}.out < cmp.in > comp2.out')
    if os.system(f'diff comp1.out comp2.out'):
        break
else:
    print('suc')