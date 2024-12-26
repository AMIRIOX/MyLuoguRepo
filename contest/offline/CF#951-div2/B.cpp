// !unaccepted: TLE on #5
/*
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
int t, x, y;
signed main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &x, &y);
        int k = x^y; long long m = 1;
        // find j = i^x^y, i.e. j=i^k
        for(long long i = 0; i<=100; i++) {
            long long j=i^k;
            for(m = 1; (j+m) == ((i+m)^k); m++) if(m > 1e9) break;
            if(m!=1) break;
        }
        printf("%lld\n", m);
    }
    return 0;
}
*/

// correct answer
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
int t, x, y;
signed main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &x, &y);
        int k = x^y;
        printf("%d\n", k&(-k));
    }
    return 0;
}
