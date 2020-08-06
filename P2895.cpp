#include <bits/stdc++.h>
using namespace std;
#define MAXN 310 
struct pos {
    int x, y;
};
// int min(int a, int b) { return a > b ? b : a; }
int death[MAXN][MAXN], _ans[MAXN][MAXN];
int mov[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
queue<pos> Q;
int main() {
    int m, Ans = 100000;
    memset(_ans, -1, sizeof _ans);
    memset(death, 0x7fffffff, sizeof death);
    cin >> m;
    //cout << m << ":::\n";
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
#define REC(x, y, t) \
    if (x >= 0 && y >= 0) death[x][y] = min(death[x][y], t);
        REC(x, y, t);
        for (int j = 0; j < 4; j++) {
            REC(x + mov[j][0], y + mov[j][1], t);
        }
        //cout << m<< " " << i << endl;
    }
    Q.push((pos){0, 0});
    _ans[0][0] = 0;
    // while (!Q.empty()) {
    //     pos p = Q.front();
    //     int ux = p.x, uy = p.y;
    //     Q.pop();
    //     for (int i = 0; i < 4; i++) {
    //         int x = ux + mov[i][0], y = uy + mov[i][1];
    //         cout << "...0";
    //         if (x < 0 || y < 0 || _ans[x][y] != -1 ||
    //             /*death[x][y] <= _ans[ux][uy] + 1)*/
    //             _ans[ux][uy] + 1 >= death[x][y])
    //             continue;
    //             cout <<"__";
    //         _ans[x][y] = _ans[ux][uy] + 1;
    //         Q.push((pos){x, y});
    //     }
    // }
    while (!Q.empty()) {
        pos u = Q.front();
        int ux = u.x, uy = u.y;
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int x = ux + mov[k][0], y = uy + mov[k][1];
            if (x < 0 || y < 0 || _ans[x][y] != -1 ||
                _ans[ux][uy] + 1 >= death[x][y])
                continue;
            _ans[x][y] = _ans[ux][uy] + 1;
            Q.push((pos){x, y});
        }
    }
    for (int i = 0; i <= 305; i++) {
        for (int j = 0; j <= 305; j++) {
            if (death[i][j] > 1000 && _ans[i][j] != -1) {
                Ans = min(Ans, _ans[i][j]);
                cout <<".";
            }
                
        }
    }
    cout << ((Ans == 100000) ? -1 : Ans);
    cout << endl;
    return 0;
}