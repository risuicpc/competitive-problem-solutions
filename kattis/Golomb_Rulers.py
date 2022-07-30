from sys import stdin

for t in stdin:
    y = [int(j) for j in t.split()]
    b, y, x = True, sorted(y), {}
    for i in range(y[-1]+1):
        x[i] = False
    c = 0
    for i in range(len(y)):
        for j in range(i+1, len(y)):
            if x[y[j] - y[i]]:
                b = False
                break
            else:
                x[y[j] - y[i]] = True
                c += 1
        if not b:
            break

    if not b:
        print('not a ruler')
    else:
        if c == y[-1]:
            print('perfect')
        else:
            print('missing ', end='')
            for i in range(1, y[-1]+1):
                if not x[i]:
                    print(i, end=' ')
            print()
