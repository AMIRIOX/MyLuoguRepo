#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 10; //TODO

int n, q;
int I[maxn], Z[maxn];
int ans[maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> q;
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '1') I[i + 1] = 1;
        else if(s[i] == '2') Z[i + 1] = 1;

        I[i + 1] += I[i + 1 - 1];
        Z[i + 1] += Z[i + 1 - 1];
    }
    for(int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        long long ans = 0;
        for(int j = l; j <= r; j++) {
            if(s[j - 1] == '/') {
                ans = max(ans, min(I[j - 1] - I[l - 1], Z[r] - Z[j - 1]) * 2 + 1ll);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
