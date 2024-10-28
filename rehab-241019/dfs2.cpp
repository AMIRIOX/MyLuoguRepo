#include <bits/stdc++.h>
using namespace std;
int n, ans;
const int maxn = 1e5 + 10;
int need[maxn] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[maxn];

void dfs(int cur, int cost) {
    if(cur == 3) {
        int rem = n - 4 - need[a[1]] - need[a[2]];
        if(rem > 0 && rem == need[a[1] + a[2]]) {
            ans++;
        }
        return;
    }
    for(int i = 0; i <= 1000; i++) {
        a[cur] = i;
        dfs(cur + 1, cost + need[i]);
    }
}
signed main() {
    for(int i = 10; i <= 1000; i++) {
        int tmp = i;
        int cnt = 0;
        while(tmp > 0) {
            cnt += need[tmp % 10];
            tmp /= 10;
        }
        need[i] = cnt;
    }
    cin >> n;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
