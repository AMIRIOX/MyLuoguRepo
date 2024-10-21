#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 10;
const int mod = 1000000007;
int a[maxn], b[maxn], sum[maxn];
signed main() {
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
        a[i] %= mod;
    } 

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        sum[i] = sum[i - 1] + a[i] * b[i];
        sum[i] %= mod;
        b[i] += b[i-1];
        b[i] %= mod;
    }

    for(int i = 1; i <= m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        int ans = 0;
        if(x <= l) {
            ans += (sum[r] - sum[l - 1]) - a[x] * (b[r] - b[l - 1]);
            ans %= mod;
        }else if(x >= r) {
            ans += a[x] * (b[r] - b[l - 1]) - (sum[r] - sum[l - 1]);
            ans %= mod;
        }else {
            // l x r 
            ans += a[x] * (b[x] - b[l - 1]) - (sum[x] - sum[l - 1]);
            ans %= mod;
            ans += (sum[r] - sum[x - 1]) - a[x] * (b[r] - b[x - 1]);
            ans %= mod;
        }
        cout << (ans + mod) % mod << endl;
    }
    return 0;
}