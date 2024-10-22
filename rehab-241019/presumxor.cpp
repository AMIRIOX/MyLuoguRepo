#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int maxn = 2e5 + 10;

int a[maxn], cnt[maxn];

signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] ^ a[i - 1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) cnt[a[i] ^ a[j - 1]]++;
        for(int j = i + 1; j <= n; j++) ans += cnt[a[j] ^ a[i + 1 - 1]];
    }
    cout << ans << endl;
    return 0;
}