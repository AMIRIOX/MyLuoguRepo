#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define int long long
struct ak {
    int ind;  // 1开始
    int val;
};
bool cmp(ak ioi, ak noi) {
    if (ioi.val != noi.val)
        return (ioi.val) < (noi.val);
    else
        return ioi.ind < noi.ind;
}
ak r[10001];
int n;
signed main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        r[i].ind = i + 1;
        cin >> r[i].val;
    }
    sort(r, r + n, cmp);
    for (int i = 0, ni = n; ni >= 1; ni--, i++) {
        cout << r[i].ind << " ";
        sum += r[i].val * (ni - 1);
    }
    double ans = 1.0 * sum / n;
    printf("\n%.2lf", ans);
    return 0;
}