#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        // 让max(x1, y1) 先涨到 x2, 可以证明这个过程不存在xi == y1
        // 再让 y1 涨到 y2, 如果和x2相等了就NO
        int fin = x1 > y1 ? x2 : y2;     //fin = x2
        int secl = x1 > y1 ? y1 : x1;    //secl = y1
        int secr = x1 > y1 ? y2 : x2;    //secr = y2
        if(fin >= secl && fin <= secr) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
