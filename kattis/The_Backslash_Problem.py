import sys
for n in sys.stdin:
    n = int(n.strip())
    s = input()
    t = ''
    for _ in range(n):
        for i in s:
            if ('!' <= i <= '*') or ('[' <= i <= ']'):
                t += '\\'
            t += i
        s = t
        t = ''
    print(s)
