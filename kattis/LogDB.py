from sys import stdin
fact = dict()
for line in stdin:
    if line == '\n':
        break
    line = line.strip().replace(' ', '').split(')')
    for i in line:
        if i:
            x = i.split('(')
            if x[0] in fact.keys():
                fact[x[0]].append(x[1].split(','))
            else:
                fact[x[0]] = [x[1].split(',')]


def solve(fa, ar, c):
    for arg in fact[fa]:
        if len(ar) == len(arg):
            an = dict()
            ans = True
            for a, b in zip(ar, arg):
                if '_' not in a:
                    if a != b:
                        ans = False
                        break
                elif a != '_':
                    if a in an.keys():
                        if b != an[a]:
                            ans = False
                            break
                    else:
                        an[a] = b
            if ans:
                c += 1
    return c


for line in stdin:
    x = line.strip().replace(' ', '').split('(')
    c = solve(x[0], x[1][:-1].split(','), 0)
    print(c)
