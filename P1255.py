n=int(input());
fb=[0,1,2]
for i in range(3,n+2):
    fb.append(fb[i-1]+fb[i-2])
print(fb[n])