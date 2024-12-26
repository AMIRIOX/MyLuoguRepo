#include <iostream>
#include <numeric>
#define int long long
using namespace std;
int uhp[3030];  // Cyberpunk 3030 (雾)
int n, p1, p2, ans;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p1 >> p2;
        int p3 = p1 + p2;
        uhp[i] = uhp[i - 1] + p3 - 8;
        // else uhp[i] = uhp[i-1] - 8;
    }
    for(int i: uhp) {
        ans+=i;
    }
    // cout << endl << accumulate(uhp,uhp+n,0);
    cout << ans;
    return 0;
}