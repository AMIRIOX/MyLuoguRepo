#include <iostream>
#include <cstdio>
using namespace std;
signed main() {
    int l,n,p;
    int minx=0, maxx=0;
    scanf("%d %d", &l, &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &p);
        maxx=max(maxx, max(p, l-p+1));
        minx=max(minx, min(p, l-p+1));
    }
    printf("%d %d\n", minx, maxx);
    return 0;
}