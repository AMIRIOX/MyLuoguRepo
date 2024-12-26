#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int maxn = 1e6+1;
int h[maxn],n, ans;
int cjump(int s, int e) {
    int x = abs(h[e]-h[s]);
    return x*x;
}
signed main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> h[i]; 
    }
    sort(h,h+n+1);
    //? 0 1 2 3 4    //! n+1-i
    //? 0 1 2 3 4 5
    int last = 0;
    for(int i=0;i<=n/2;i++) {
        ans+=cjump(last,i);
        ans+=cjump(i,n-i);
        last=n-i;
    }
    cout << ans << endl;
    return 0;
}