#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
const int pw=86400;
struct po{
    int time, nation;
}pos[12200];
int n, cnt;
signed main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        int ti,ki;
        scanf("%d %d", &ti, &ki);
        for(int j=1;j<=ki;j++) {
            int xi;
            scanf("%d", &xi);
            pos[++cnt].time=ti;
            pos[cnt].nation=xi;
        }
    }
    return 0;
}