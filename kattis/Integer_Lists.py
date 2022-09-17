t = int(input())
while t > 0:
    t -= 1
    p = input()
    n = int(input())
    x = input()[1:-1].split(',')
    i, j, rev, err = 0, n, False, False
    for c in p:
        if c == 'R':
            rev = not rev
        elif rev:
            j -= 1
        else:
            i += 1

        if i > j:
            print('error')
            err = True
            break
    if not err:
        if rev:
            print('['+','.join(x[i:j][::-1])+']')
        else:
            print('['+','.join(x[i:j])+']')
