#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 5e4+10;
int t, n, a;
signed main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int last = 0, lmaxi = 0x3f3f3f3f;
        for(int i=1; i<=n; i++) {
            scanf("%d", &a); 
            if(i!=1 && max(last, a) < lmaxi) lmaxi = max(last, a); 
                
                /*maximum among ai~aj is max(last, a)
                 * maximum > k
                 * */ 
            last = a;
        }
        printf("%d\n", lmaxi-1);
    }

    return 0;
}
