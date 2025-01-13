S = input()
Q = int(input())
K = map(int, input().split())

def f(k, l):
    if l == 0:
        return S[k - 1]
    h = len(S) << (l - 1)
    if k <= h:
        return f(k, l - 1)
    return chr(ord(f(k - h, l - 1)) ^ 32)

for k in K:
    print(f(k, 60), end=" ")

