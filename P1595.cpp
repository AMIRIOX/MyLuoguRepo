#include <iostream>
#include <cstdio>
using namespace std;
long long D[50];
signed main() {
    int n;
    scanf("%d", &n);
    D[1]=0, D[2]=1;
    for(int i=3;i<=n;i++) {
        D[i]=(i-1)*(D[i-1]+D[i-2]);
    }
    printf("%lld\n", D[n]);
    return 0;
}