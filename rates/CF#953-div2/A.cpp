#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 120;
int a[maxn];
int t, n; 
signed main() {
    cin >> t;
    while(t--) {
        scanf("%d", &n);
        int maxi = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            if(i!=n && a[i] > maxi) maxi = a[i];
        }
        printf("%d\n", maxi+a[n]);
    }
    return 0;
}
