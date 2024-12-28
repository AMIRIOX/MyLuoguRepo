N, M = map(int, input().split())
xyc = []
for i in range(M):
    x, y, c = input().split()
    xyc.append((int(x), int(y), c))
xyc.sort()
min_y = 1 << 30
ans = "Yes"
for x, y, c in xyc:
    if c == "W":
        min_y = min(min_y, y)
    else:
        if y >= min_y:
            ans = "No"
print(ans)

