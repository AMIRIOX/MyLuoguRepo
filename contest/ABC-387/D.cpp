#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int x, y;
    bool ish;
    Node(int _x = 0, int _y = 0, bool _ish = false) : x(_x), y(_y), ish(_ish) {}
};

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int bfs(vector<vector<char>> &mp, Node s, Node g) {
    const int h = mp.size() - 1;
    const int w = mp[0].size() - 1;

    vector vis(h + 1, vector<int>(w + 1, 0));
    vector dis(h + 1, vector<int>(w + 1, 0x3f3f3f3f));
    dis[s.x][s.y] = 0;

    queue<Node> q;
    q.push(s);
    while (!q.empty()) {
        int ux = q.front().x, uy = q.front().y;
        bool ish = q.front().ish;
        q.pop();
        int ds = (ish ? 2 : 0);
        int dg = (ish ? 4 : 2);
        for (int i = ds; i < dg; i++) {
            int cx = ux + dx[i], cy = uy + dy[i];
            if (cx < 1 || cx > h || cy < 1 || cy > w || vis[cx][cy] || mp[cx][cy] == '#')
                continue;
            dis[cx][cy] = dis[ux][uy] + 1;
            q.push(Node(cx, cy, !ish));
            vis[cx][cy] = 1;
        }
    }
    return dis[g.x][g.y];
}
void solve() {
    int h, w;
    cin >> h >> w;
    vector mp(h + 1, vector<char>(w + 1, ' '));
    Node s, g;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S')
                s = Node(i, j);
            if (mp[i][j] == 'G')
                g = Node(i, j);
        }
    }

    int ans = min(bfs(mp, Node(s.x, s.y, false), g), bfs(mp, Node(s.x, s.y, true), g));
    if(ans == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
