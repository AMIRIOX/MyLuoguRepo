#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 1000010
using namespace std;
vector<int> gr[MAXN];
queue<int> q;
bool vis[MAXN];
void dfs(int x) {
    cout << x << " ";
    for (int i = 0, sz = gr[x].size(); i < sz; i++) {
        if (!vis[gr[x][i]]) {
            vis[gr[x][i]] = true;
            dfs(gr[x][i]);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(gr[i].begin(),gr[i].end());
    }
    // DFS
    vis[1] = true;
    dfs(1);
    cout << endl;
    // BFS
    memset(vis, 0, sizeof vis);
    vis[1] = true;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < gr[x].size(); i++) {  // TODO:
            if (!vis[gr[x][i]]) {
                vis[gr[x][i]] = true;
                q.push(gr[x][i]);
            }
        }
    }
    return 0;
}