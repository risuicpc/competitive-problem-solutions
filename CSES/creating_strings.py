from itertools import permutations

perm = permutations(sorted(input()))
x = set()
for i in perm:
    x.add("".join(i))
x = sorted(list(x))
print(len(x))
for i in x:
    print(i)
