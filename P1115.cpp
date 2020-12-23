#include <iostream>
#define int long long
using namespace std;
const int inf = 0x7fffffff;
int n, a[100010], pre[100010], ans = -inf;
signed main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        pre[i] = pre[i-1]+a[i];
    }
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            // pre[j]-pre[i-1]
            ans = max(ans, pre[j]-pre[i-1]);
        }
    }
    cout << ans << endl;
    return 0;
}