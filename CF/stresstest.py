from os import WEXITSTATUS, system
import random


bffile = './1364Abf'
file = './1364A'
inp = './in'


def compare():
    system(bffile)
    system(file)
    ret = WEXITSTATUS(system('diff outbf out'))
    if(ret != 0):
        raise Exception("Wrong Answer")
    else:
        print("Accepted")



def generate_tc(n, arr):
    if len(arr) == n:
        if arr[0] == 0: return
        inp_file = open(inp, 'w')
        inp_file.write(f'1\n{len(arr) - 1} {arr[0]}\n')
        for i in range(1, len(arr)):
            inp_file.write(f'{arr[i]} ')
        inp_file.close()
        compare()
        return
    for i in range(0, 6):
        arr.append(i)
        generate_tc(n, arr)
        arr.pop()

generate_tc(5, [])
