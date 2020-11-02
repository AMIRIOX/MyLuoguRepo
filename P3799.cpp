#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;
int staff[maxn], n, have[maxn], minx = INF, maxx = -INF, ans;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> staff[i];
        if (staff[i] < minx) minx = staff[i];
        if (staff[i] > maxx) maxx = staff[i];
        have[staff[i]]++;
    }
    for (int i = minx; i <= maxx; i++) {
        //! i=i=(j+k)
        for (int j = i; j >= 0; j--) {
            if (i == j) continue;
            if (have[i] >= 2) {
                if ((i - j) == j && have[i - j] >= 2) {
                    ans++;
                    continue;
                }
                if (have[i - j]) ans++;
            }
        }
    }
    cout << ans % mod << endl;
    return 0;
}