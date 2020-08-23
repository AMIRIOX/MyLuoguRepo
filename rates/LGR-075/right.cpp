#include <bits/stdc++.h>
#define re register
#define int long long
using namespace std;
signed main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    if (abs(a - b) >= c)
        a > b ? b += c : a += c;
    else {
        a > b ? c -= (a - b), b = a : c -= (b - a), a = b;
        a += (c / 2), b += (c / 2);
    }
    cout << a << ' ' << b << endl;
    int x = min(a, b);
    re int ans;
    for (ans = sqrt(x * 2) - 1; ans * (ans + 1) <= 2 * x; ++ans)
        ;
    printf("%lld", ans - 1);
    return 0;
}
