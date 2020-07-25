import os

gen = 'gen2'
sol = '../solution'
subtaskNum = 2
taskNum = 20

for cnt in range(20):
    infile = f'../test/{subtaskNum}_{cnt}.in'
    outfile = f'../test/{subtaskNum}_{cnt}.out'
    os.system(f'g++ -std=c++14 -o {sol}.out {sol}.cpp')
    os.system(f'python3 {gen}.py > {infile}')
    os.system(f'./{sol}.out < {infile} > {outfile}')