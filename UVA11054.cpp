#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
const int maxn = 1e5+10;

signed main() {
    int n = 0;
    while(cin >> n && n!=0) {
        int tot = 0, ans = 0;
        for(int i=1;i<=n;i++) {
            int x;
            cin >> x;
            tot+=x;
            ans+=abs(tot);
        }
        cout << ans << endl;
    }
    return 0;
}