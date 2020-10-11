#include <algorithm>
#include <cstdio>
#include <iostream>
#define int long long
#define INF 9000000000000000000

using namespace std;
const int maxn = 1e6 + 1;
int n, m;
int a[maxn];
bool check(int x) {
    /* version 1*/
    // int cur = 0, c = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (cur + a[i] <= x)
    //         cur += a[i];
    //     else
    //         cur = a[i], c++;
    // }
    // return c < m;

    /*version2*/
    // 每段最大值
    int cur = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (cur + a[i] <= x) cur += a[i];
        else {
            c++;
            cur = a[i];
        }
    }
    if (c < m) return true;
    return false;
}
signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int L = *(std::max_element(a + 1, a + n - 1)), R = 1e9 + 1, ans = INF;
    while (L < R) {
        int mid = L + (R - L) / 2;
        if (check(mid)) {
            ans = min(ans, mid);
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}