q = int(input())
while q > 0:
    q -= 1
    k = int(input())
    if k < 10:
        print(k)
    else:
        for i in range(18):
            d = 9 * (10**i)
            if k > d * (i+1):
                k -= d * (i+1)
            else:
                d, r = k // (i+1), k % (i+1)
                ans = 10**i + d
                if r > 0:
                    print(str(ans)[r-1])
                else:
                    print((ans-1) % 10)
                break
