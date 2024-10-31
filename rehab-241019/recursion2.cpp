#include <bits/stdc++.h>
using namespace std;

void foo(int n) {
    // display
    // 2(foo(log2(n))) + foo(n - (1 << log2(n)))
    // 注意递归终止条件
    if(n == 0) cout << "0";
    else if(n == 1) cout << "2(0)";
    else if(n == 2) cout << "2";
    else {
        int i = log2(n);
        if(i == 1) {
            cout << "2";
        }else if(i >= 1) {
            cout << "2(";
            foo(i); 
            cout << ")";
        }
        n -= (1 << i);
        if(n > 0) {
            if(i) cout << "+";
            foo(n);
        }
    }
}

signed main() {
    int n;
    //cin >> n;
    while(cin >> n) foo(n), cout << endl;
    return 0;
}
