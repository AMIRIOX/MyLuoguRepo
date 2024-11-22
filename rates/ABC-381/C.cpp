#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 10; //TODO

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;
    long long ans = 0;
    for(int i = s.find("/", 0); i != string::npos; i = s.find("/", i + 1)) {
        long long cnt = 1;
        for(int dt = 1; i - dt >= 0 && i + dt < s.length(); dt++) {
            if(s[i - dt] != '1' || s[i + dt] != '2') {
                break;
            }else {
                cnt += 2;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
