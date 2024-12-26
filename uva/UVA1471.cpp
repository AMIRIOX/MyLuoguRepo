#include <cstdio>
#include <limits>
#include <cstring>
#include <iostream>
// #define int long long
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int begint[maxn], endt[maxn];
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n = 0, ans = 0;
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 求以a[i]开头的最长递增序列
        for (int i = 0; i < n; i++) {
            int last = a[i];
            int cnt = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] <= last)
                    break;
                else
                    cnt++, last = a[j];
            }
            begint[i] = cnt;
        }

        // 求a[i]结尾的最长递增序列
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                endt[i] = 1;
                continue;
            }
            int last = a[i];
            int cnt = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] >= last)
                    break;
                else
                    cnt++, last = a[j];
            }
            endt[i] = cnt;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || a[i] >= a[j]) continue;
                ans = max(ans, endt[i] + begint[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}