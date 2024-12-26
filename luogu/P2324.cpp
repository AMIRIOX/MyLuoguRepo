#include <cstdio>
#include <iostream>
#define SWAP(jshhdh, jhjdad)     \
    do {                         \
        register int x = jshhdh; \
        jshhdh = jhjdad;         \
        jhjdad = x;              \
    } while (0);
using namespace std;
const int maxn = 1e5 + 10;
const int dx[] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

const int goal[7][7]{
    {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1},
    {0, 0, 0, 2, 1, 1}, {0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0},
};
int mp[7][7], suc = 0;
inline int eval() {
    // 乐观估价函数
    int cnt = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (mp[i][j] != goal[i][j]) cnt++;
        }
    }
    return cnt;
}
inline int check(int x, int y) {
    // 检查越界
    if (x < 1 || x > 5 || y < 1 || y > 5) return 0;
    return 1;
}
inline void iterativeDeepeningAStar(int depth, int startX, int startY,
                                    int maxd) {
    // IDA*
    if (depth == maxd) {
        if (!eval()) suc = 1;
        return;
    }
    for (register int i = 1; i <= 8; i++) {
        register int nextX = startX + dx[i];
        register int nextY = startY + dy[i];
        if (check(nextX, nextY)) {
            SWAP(mp[startX][startY], mp[nextX][nextY]);
            if (eval() + depth <= maxd)
                iterativeDeepeningAStar(depth + 1, nextX, nextY, maxd);
            SWAP(mp[startX][startY], mp[nextX][nextY]);
        }
    }
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        register char o;
        suc = 0;
        int sx = 0, sy = 0;
        for (register int i = 1; i <= 5; i++)
            for (register int j = 1; j <= 5; j++) {
                cin >> o;
                if (o == '*')
                    mp[i][j] = 2, sx = i, sy = j;
                else
                    mp[i][j] = (o ^ 48);
            }
        if (!eval()) {
            printf("0\n");
            continue;
        }
        for (register int m = 1; m <= 15; m++) {
            iterativeDeepeningAStar(0, sx, sy, m);
            if (suc) {
                cout << m << endl;
                goto OK;
            }
        }
        printf("-1\n");
    OK:;
    }
    return 0;
}