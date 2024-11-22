#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 10; //TODO

int n;
int a[maxn], cnt[maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    //11 22 33 11 44 55
    long long ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i + 1]) {
            int l = i, r = i;
            cnt[a[i]] += 2;
            while(l <= r && r + 1 <= n && a[r] == a[r + 1]) {
                while(r + 3 <= n && a[r + 2] == a[r + 3] && !cnt[a[r + 2]]) {
                    r += 2;
                    cnt[a[r]] += 2;
                }
                ans = max(ans, r + 1 - l + 1ll);
                cnt[a[l]] -= 2;
                l += 2;
            }
            i = r;
        }
    }
    cout << ans << endl;
    return 0;
}
