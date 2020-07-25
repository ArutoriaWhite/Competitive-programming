import os

gen = 'gen_5'
sol = '../solution/nlogn'
subtaskNum = 5
taskNum = 10

for cnt in range(taskNum):
    infile = f'../test/{subtaskNum}_{cnt}.in'
    outfile = f'../test/{subtaskNum}_{cnt}.out'
    os.system(f'g++ -std=c++14 -o {sol}.out {sol}.cpp')
    os.system(f'python3 {gen}.py > {infile}')
    os.system(f'./{sol}.out < {infile} > {outfile}')