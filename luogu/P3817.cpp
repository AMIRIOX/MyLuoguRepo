#include <iostream>
using namespace std;
#define int long long
#define MAXN (int)1e5 + 5
int n, x, a[MAXN], ans;
signed main() {
    #ifdef LOCAL
       freopen("P3817_2.in","r",stdin);
       cout << "defined local.\n";
    #endif
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0 && a[i] > x) {
            int c = a[0] - x;
            a[0] -= c;
            ans += c;
            //cout << c <<" "<< a[i] << ">" << x << endl;
        } else if (a[i] + a[i - 1] > x) {
            int c = (a[i] + a[i - 1]) - x;
            a[i] -= c;
            ans += c;
            //cout << c <<" "<< a[i] << "+" << a[i-1] << ">" << x << endl;
        }
    }
    cout << ans;
    return 0;
}