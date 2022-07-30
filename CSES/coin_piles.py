from re import X


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    a, b = max(a, b), min(a, b)
    if a <= 2 * b and (a + b) % 3 == 0:
        print("YES")
    else:
        print("NO")
