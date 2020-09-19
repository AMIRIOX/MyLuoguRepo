#include <cmath>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], m, p1, s1, s2;
int dragon, tiger, p2, now;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;
    for (int i = 1; i < m; i++) {
        dragon += (a[i] * (m - i));
    }
    for (int i = m + 1; i <= n; i++) {
        tiger += (a[i]) * (i - m);
    }
    p2 = m;
    now = abs(dragon - tiger);
    for (int i = 1; i <= n; i++) {
        if (i < m) {
            //cout << "i<m" << endl;
            dragon += (m - i) * s2;
            int cur = abs(dragon - tiger);
            //cout << cur << ">=" << now << endl;
            if (cur < now) {
                //cout << "update" << endl;
                now = cur;
                p2 = i;
            }
            dragon -= (m - i) * s2;
        } else if (i > m) {
            //cout << "i>m" << endl;
            tiger += (i - m) * s2;
            int cur = abs(dragon - tiger);
            //cout << cur << ">=" << now << endl;
            if (cur < now) {
                //cout << "update" << endl;
                now = cur;
                p2 = i;
            }
            tiger -= (i - m) * s2;
        }
    }
    cout << p2;
    return 0;
}