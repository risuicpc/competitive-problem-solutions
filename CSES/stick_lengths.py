n = int(input())
p = sorted([int(i) for i in input().split()])
m = p[n//2] if n % 2 == 1 else (p[n//2 - 1] + p[n//2]) // 2
ans = sum([abs(m - i) for i in p])
print(ans)
