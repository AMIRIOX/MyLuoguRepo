#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
struct tt{
    int a, b;
    tt(int _a = 0, int _b = 0) {this->a = _a; this->b = _b;}
}tts[maxn];
int b[maxn];
void solve() {
    int n, m;
    cin >> n >> m;
    memset(b, 0, sizeof b);
    for(int i = 1; i <= n; i++) {
        cin >> tts[i].a >> tts[i].b;
    }
    for(int i = 1; i <= m; i++) {
        int tmp; cin >> tmp;
        b[1]++;
        b[tmp+1]--;
    }
    int bcur = 0;
    for(int i = 1; i <= n; i++) {
        bcur += b[i];
        tts[i].b += bcur;
    }
    int ans = 0;
    int maxd[2] = {0, 0};
    for(int i = n; i >= 1; i--) {
        if(tts[i].b < maxd[1 - tts[i].a]) {
            ans++;
        }
        maxd[tts[i].a] = max(maxd[tts[i].a], tts[i].b);
    }
    cout << n - ans << endl;
}
signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}