#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 10;
int n;
int f[maxn];

// f[i] 代表 i 开头的方案数
// f[i] = f[1] + f[2] + f[3] + ... + f[i/2]
signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) f[i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            f[i] += f[j];
        }
    }
    cout << f[n] << endl;
    return 0;
}
