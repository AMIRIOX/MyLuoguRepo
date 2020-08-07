#include <bits/stdc++.h>
using namespace std;
#define maxn 310
struct coord {
    int x, y;
};
queue<coord> Q;
int ans[maxn][maxn], death[maxn][maxn];
int wk[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int main() {
    int m, Ans = 100000;
    memset(ans, -1, sizeof ans);
    memset(death, 0x7f, sizeof death);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
#define MIN(x, y, t) \
    if (x >= 0 && y >= 0) death[x][y] = min(death[x][y], t)
        MIN(x, y, t);
        for (int k = 0; k < 4; k++) {
            MIN(x + wk[k][0], y + wk[k][1], t);
        }
    }
    Q.push((coord){0, 0});
    ans[0][0] = 0;
    while (!Q.empty()) {
        coord u = Q.front();
        int ux = u.x, uy = u.y;
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int x = ux + wk[k][0], y = uy + wk[k][1];
            if (x < 0 || y < 0 || ans[x][y] != -1 ||
                ans[ux][uy] + 1 >= death[x][y])
                continue;
            ans[x][y] = ans[ux][uy] + 1;
            Q.push((coord){x, y});
        }
    }
    for (int i = 0; i <= 305; i++)
        for (int j = 0; j <= 305; j++)
            if (death[i][j] > 1000 && ans[i][j] != -1)
                Ans = min(Ans, ans[i][j]);
    if (Ans == 100000)
        puts("-1");
    else
        printf("%d", Ans);
    return 0;
}