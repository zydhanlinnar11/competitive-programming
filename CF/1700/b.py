t = int(input())

for i in range(0, t):
    n = int(input())
    bil = int(input())
    s = int(''.join(['9' for x in range(0, n)]))
    alt = int(''.join(['1' for x in range(0, n + 1)]))
    diff = s - bil
    if diff != 0 and len(str(diff)) == n:
        print(diff)
    else: print(alt - bil)
    