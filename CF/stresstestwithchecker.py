from os import WEXITSTATUS, system
import random


file = './1364C'
inp = './in'
outp = './out'


def check(arr: 'list[str]'):
    status = system(file)
    if WEXITSTATUS(status) != 0:
        print('RTE')
        exit(1)
    foutput = open(outp)
    ans = [int(x) for x in foutput.readline().split(' ')]
    if ans[0] == -1:
        # print("Accepted")
        return
    mxx = [x for x in range(0, 1000001)]
    for i in range(0, len(arr)):
        if ans[i] in mxx:
            mxx.remove(ans[i])
        if int(arr[i]) != mxx[0]:
            print('Wrong Answer')
            exit(1)
    # print("Accepted")


def generate_tc(n: 'int', arr: 'list[str]'):
    if len(arr) == n:
        finput = open(inp, 'w')
        finput.write(f'{str(n)}\n')
        finput.write(' '.join(arr) + '\n')
        finput.close()
        check(arr)
        # exit(0)
        return
    for i in range(1, 11):
        arr.append(str(i))
        generate_tc(n, arr)
        arr.pop()


n = 5
generate_tc(n, [])
# inp_file = open(inp, 'w')
# inp_file.write(f'{len(arr)}\n')
# for i in range(0, len(arr)):
#     inp_file.write(f'{str(n)}\n{arr[i]}\n')

# inp_file.close()
# compare()

# print(arr)
