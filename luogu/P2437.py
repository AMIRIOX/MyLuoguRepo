n,m=map(int,input().split())
f = [0 for _ in range(m+10)]
f[n]=1
f[n+1]=1
for index in range(n+2,m+1):
    f[index]=f[index-1]+f[index-2]
print (f[m])
