n = int(input())

an = 0
f1 = 25
while f1 <= n:
    an += n // f1
    f1 *= 5
an += n//5
print(an)
