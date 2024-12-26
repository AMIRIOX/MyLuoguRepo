#include <bits/stdc++.h>
using namespace std;

void solve() {
    int al = 0, ar = 0, bl = 0, br = 0;
    cin >> al >> ar >> bl >> br;
    
    // 不重复直接输出1
    if(ar < bl || br < al) {
        cout << 1 << endl;
        return;
    }
    // 区间相接
    if(ar == bl || br == al) {
        cout << 2 << endl;
        return;
    }
    // 区间相等
    if(al == bl && ar == br) {
        cout << ar - al << endl;
        return;
    }
    // 区间包含
    if(bl <= al && ar <= br) {
        if(al == bl || ar == br) cout << ar - al + 1 << endl;
        else cout << ar - al + 2 << endl;
        return;
    }else if(al <= bl && br <= ar) {
        if(bl == al || br == ar) cout << br - bl + 1<< endl;
        else cout << br - bl + 2 << endl;
        return;
    }
    
    if(al < bl) {
        // al bl ar<=br
        cout << ar - bl + 2<< endl;
    }else {
        // bl<=al br ar
        cout << br - al + 2 << endl;
    }
}        

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
