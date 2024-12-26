#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
vector<int> gr[maxn];
int cowOnThisPoint[maxn], k, n, m, ans, vis[maxn], sir[maxn];
void dfs(int x /*, int tmp*/) {
    // if (cowOnThisPoint[x] != 0) tmp++;
    // if (tmp == n) ans++, tmp = 0;
    // if (gr[x].size() == 0) {
    //     // 出度为0的节点
    //     return;
    // }
    // for (int i = 0; i < gr[x].size(); i++) {
    //     dfs(gr[x][i], tmp);
    // }
    sir[x]++,vis[x]=1;
    for (int i = 0; i < gr[x].size(); i++) {
        if (!vis[gr[x][i]] && gr[x][i] != x) dfs(gr[x][i]);
    }
}
int main() {
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++) {
        cin >> cowOnThisPoint[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
    }
    // cout << "ok";
    for (int i = 1; i <= k; i++) {
        memset(vis, 0, sizeof vis);
        dfs(cowOnThisPoint[i]);
    }
    for (int i = 1; i <= n; i++)
        if (sir[i] == k) ans++;
    // for (int i = 1; i <= n; i++) dfs(i, 0);
    cout << ans;
    return 0;
}