trampolines: 'list[tuple[int, int, int]]' = []
visited: 'list[bool]' = []

def dfs(s, n, curr):
    global trampolines
    global visited
    # print(visited)
    # print(curr)
    visited[curr] = True
    (x_curr, y_curr, p_curr) = trampolines[curr]
    for i in range(0, n):
        if visited[i]: continue
        (x_dst, y_dst, p_dst) = trampolines[i]
        dist = abs(x_dst - x_curr) + abs(y_dst - y_curr)
        if (p_curr * s) < dist: continue
        dfs(s, n, i)

def can(s: 'int', n: 'int'):
    global trampolines
    global visited
    for i in range(0, n):
        visited = [False for x in range(0, n)]
        dfs(s, n, i)
        if min(visited) == True: return True
    return False


n = int(input())
for i in range(0, n):
    (x, y, p) = input().split(' ')
    x = int(x)
    y = int(y)
    p = int(p)
    trampoline = (x, y, p)
    trampolines.append(trampoline)

l = 0
r = int(10e18)
mid = 0

while l <= r:
    mid = l + (r - l) // 2
    if l == r: break
    if can(mid, n):
        r = mid
    else:
        l = mid + 1

print(mid)