#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int mov[8][2] = {{2,1}, {-2,1}, {1,2}, {-1,2}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};
int n, m, ox, oy, ans[500][500];
struct pos {
    int x;
    int y;
};
queue<pos> Q;
int main() {
    cin >> n >> m >> ox >> oy;
    pos start = {ox, oy};
    Q.push(start);
    memset(ans, -1, sizeof ans);
    ans[ox][oy] = 0;
    while (!Q.empty()) {
        pos current = Q.front();
        Q.pop();
        int lx = current.x, ly = current.y;
        for (int i = 0; i < 8; i++) {
            int x = lx + mov[i][0], y = ly + mov[i][1];
            if (x < 1 || x > n || y < 1 || y > m || ans[x][y] != -1) continue;
            int ld = ans[lx][ly];
            ans[x][y] = ld+1;
            pos nex = {x,y};
            Q.push(nex);
        }
    }
    for(int i=1;i<=n;i++,puts("")) {
        for(int j=1;j<=m;j++) {
            printf("%-5d",ans[i][j]);
        }
    }
    return 0;
}