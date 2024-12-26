#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int maxn = 2e5 + 10;

inline int read() {
    int val = 0, flg = 1;
    char ch = (char) getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') flg = 0;
        ch = (char) getchar();
    }
    while(ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char) getchar();
    }
    return flg ? val : ~(val - 1);
}
int n, tmp, k;
int a[maxn];

map<int, int> mp;
priority_queue<int, vector<int>, greater<int> > q[maxn];
signed main(void) {
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        if(!mp.contains(a[i])) mp[a[i]] = ++k; 
        
        if(!mp.contains(a[i] - 1) || q[mp[a[i] - 1]].empty()) {
            q[mp[a[i]]].push(1);
        }else {
            int ed = q[mp[a[i] - 1]].top() + 1;
            q[mp[a[i] - 1]].pop();
            q[mp[a[i]]].push(ed);
        }
    }
    int ans = 2e18;
    for(int i = 1; i <= n; i++) {
        if(q[mp[a[i]]].size()) ans = min(ans, (int)q[mp[a[i]]].top());
    }
    cout << ans << endl;
    return 0;
}
