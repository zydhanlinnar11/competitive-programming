from math import ceil, log10


(n, k) = input().split(' ')
n = int(n)
k = int(k)

if k >= ceil(102 / log10(2)) or 2 ** k >= n:
    print('Your wish is granted!')
else: print('You will become a flying monkey!')
