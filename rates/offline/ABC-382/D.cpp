#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, tot;
int ans[maxn + 10];

vector<vector<int> > out;

// Ai最大 m - 10 * n
void dfs(int cur, int lst) {
    if(cur > n) {
        out.push_back(vector<int>(ans + 1, ans + n + 1));
        return;
    }
    for(int i = lst + 10; i <= m - 10 * (n - cur); i++) {
        ans[cur] = i;
        dfs(cur + 1, i);
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> m;
    dfs(1, -9);
    cout << out.size() << '\n';
    for(const auto &ansi : out) {
        for(const auto &i : ansi) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
