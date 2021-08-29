#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<string, int> m;
// using pss = pair<string, string>;
// pss ts[10020];
signed main() {
    int n;
    bool ok = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        string x, y;
        cin >> x >> y;
        if (!ok) {
            x += "|";
            x += y;
            if (m.count(x))
                ok = true;
            m[x]++;
        }
    }
    printf((ok == true) ? ("Yes\n") : ("No\n"));
    // sort(ts + 1, ts + n + 1,
    //      [=](pss x, pss y) { return x.first[0] < y.first[0]; });
    // while(1) {

    // }

    return 0;
}