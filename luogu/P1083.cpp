#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e6 + 10;
int n, m; // day, order
int r[maxn], d[maxn];
int s[maxn], t[maxn];
long long b[maxn];

bool check(int j) {
    long long cur = 0;
    memset(b, 0, sizeof b);
    for(int i = 1; i <= j; i++) {
        b[s[i]] += d[i];
        b[t[i] + 1] -= d[i];
    }
    for(int i = 1; i <= n; i++) {
        cur += b[i];
        if(cur > r[i]) return true;
    }
    return false;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> r[i];
    for(int i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];

    if(!check(m)) {
        cout << 0 << endl;
        return 0;
    }
    
    int L = 1, R = m;
    while(L < R) {
        int mid = (L + R) >> 1;
        if(check(mid)) R = mid;
        else L = mid + 1;
    }
    cout << -1 << endl << L << endl;
    return 0;
}
