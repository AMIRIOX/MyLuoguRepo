#include <cstdio>
#include <iostream>
#include <set>
// #define int long long
using namespace std;
const int maxn = 1e6 + 10;
int snowflakes[maxn];
signed main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> snowflakes[i];
        int L = 0, R = 0, ans = 0;
        set<int> s;
        while (R < n) {
            while (R < n && !s.count(snowflakes[R])) s.insert(snowflakes[R++]);
            ans = max(ans, R - L);
            s.erase(snowflakes[L++]);
        }
        cout << ans << endl;
    }
    return 0;
}