#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 100010;
inline int max(int a, int b) { return ((a > b) ? a : b); }
struct edge {
    int to;
    int dis;
    edge(int _to = 0, int _dis = 0) : to(_to), dis(_dis) {}
};
vector<edge> gr[MAXN];
queue<int> q;
int n, m, longer[MAXN], ind[MAXN];
//! dfs TLE #4 #5 #6
// void dfs(int x, int d) {
//     if (x == n) {
//         ans = max(ans,d);
//     }
//     for(int i=0,sz=gr[x].size();i<sz;i++) {
//         dfs(gr[x][i].to,d+gr[x][i].dis);
//     }
// }
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        gr[x].push_back((edge){y, v});
        ind[y]++;
    }
    // dfs(1,0);
    for (int i = 1; i <= n; i++) {
        longer[i] = -1;
        if (!ind[i] && i != 1) {
            for (int j = 0; j < gr[i].size(); j++) ind[gr[i][j].to]--;
        }
    }
    longer[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0, sz = gr[x].size(); i < sz; i++) {
            if (longer[gr[x][i].to] < longer[x] + gr[x][i].dis)
                longer[gr[x][i].to] = longer[x] + gr[x][i].dis;
            if (!(--ind[gr[x][i].to])) q.push(gr[x][i].to);
        }
    }
    cout << longer[n];
    // cout << ans << endl;
    return 0;
}