from os import WEXITSTATUS, system
import random


bffile = './1697Cbf'
file = './1697C'
inp = './in'


def compare():
    system(bffile)
    system(file)
    ret = WEXITSTATUS(system('diff outbf out'))
    if(ret != 0):
        raise Exception("Wrong Answer")
    else:
        print("Accepted")


arr = []


def generate_tc(n, s):
    if len(s) == n:
        arr.append(s)
        return
    for i in 'abc':
        generate_tc(n, s + i)


n = 4
generate_tc(n, '')
for i in range(0, len(arr)):
    for j in range(i+1, len(arr)):
        inp_file = open(inp, 'w')
        inp_file.write(f'1\n{str(n)}\n{arr[i]}\n{arr[j]}\n')
        inp_file.close()
        compare()

# print(arr)
