#include <bits/stdc++.h>
#include <cstring>
using namespace std;

using ll = long long;

ll h, w, d;
char s[1020][1020];
bool vis[1020][1020];

bool ok(int i, int j) {
    if (i < 1 || i > h || j < 1 || j > w)
        return false;
    return true;
}

ll ans;
ll dis[1020][1020];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

/*
void dfs(int cx, int cy, int cd) {
    if(cd > d) return;
    for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir], ny = cy + dy[dir];
        if(ok(nx, ny)){
            if(s[nx][ny] == '#') continue;
            if(s[nx][ny] == '.' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                ans++;
            }
            if(s[nx][ny] != 'H') dfs(nx, ny, cd + 1);
        }
    }

}
*/

struct node {
    int x, y;
    node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> h >> w >> d;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> s[i][j];
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (s[i][j] != 'H')
                continue;
            memset(vis, 0, sizeof vis);
            queue<node> q;
            q.push(node(i, j));
            vis[i][j] = true;
            dis[i][j] = 0;
            while (!q.empty()) {
                int cx = q.front().x, cy = q.front().y;
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cx + dx[dir], ny = cy + dy[dir];
                    if (!ok(nx, ny) || s[nx][ny] != '.' || vis[nx][ny] ||
                            dis[nx][ny] <= dis[cx][cy] + 1)
                        continue;
                    dis[nx][ny] = dis[cx][cy] + 1;
                    vis[nx][ny] = true;
                    q.push(node(nx, ny));
                }
            }
            //            dfs(i, j, 1);
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            ans += (dis[i][j] <= d);
        }
    }
    cout << ans << '\n';
    return 0;
}
