// 差分

#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;
int Q, n, a[maxn], fid[maxn];
signed main() {
    cin >> Q >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (Q--) {
        int L, R, val;
        cin >> L >> R >> val;
        fid[L] += val;
        fid[R + 1] -= val;
    }

    int incr = 0;
    for (int i = 1; i <= n; i++) {
        //   3  -3
        // 1 2 3 4 5
        // 1 5 6 4 5
        // 1 6 12 16 21
        // +
        //  -3   3
        // 1 2 3 4 5
        incr += fid[i];
        a[i] += a[i - 1] + incr;
    }
    int intervalLeft, intervalRight;
    cin >> intervalLeft >> intervalRight;
    cout << a[intervalRight] - a[intervalLeft - 1] << endl;
    // for(int i=1;i<=n;i++) {
    //     cout << a[i] << " ";
    // }
    return 0;
}