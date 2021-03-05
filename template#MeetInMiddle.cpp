#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct xf {
    int x, y;
    string stu;
    xf(int _x, int _y, string _s) : x(_x), y(_y), stu(_s) {}
};
map<string, int> onemp;
const string aim = "111110111100*110000100000";
int mov[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                 {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

bool onebfs(string status, int sxi, int syi) {
    queue<xf> q;
    q.push(xf(sxi, syi, status));
    onemp[status] = 1;
    while (!q.empty()) {
        xf cur = q.front();
        q.pop();
        if (onemp[cur.stu] == 8)
            break;
        if (cur.stu == aim) {
            printf("%d\n", onemp[cur.stu] - 1);
            return true;
        }
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + mov[i][0];
            int ny = cur.y + mov[i][1];
            if (nx < 1 || nx > 5 || ny < 1 || ny > 5)
                continue;
            string nxs = cur.stu;
            // swap(nxs[(cur.x - 1) * 5 + cur.y - 1], nxs[(nx - 1) * 5 + ny -
            // 1]);
            int targeta = (cur.x - 1) * 5 + cur.y - 1;
            int targetb = (nx - 1) * 5 + ny - 1;
            char tps = nxs[targeta];
            nxs[targeta] = nxs[targetb];
            nxs[targetb] = tps;
            if (onemp[nxs] == 0) {
                onemp[nxs] = onemp[cur.stu] + 1;
                q.push(xf(nx, ny, nxs));
            }
        }
    }
    return false;
}
void twobfs(int sxi, int syi, string status) {
    map<string, bool> twomp;
    queue<xf> q;
    q.push(xf{sxi, syi, aim});
    twomp[status] = true;
    onemp[status] = 1;
    while (!q.empty()) {
        xf cur = q.front();
        q.pop();
        if (onemp[cur.stu] == 9) {
            printf("-1\n");
            return;
        }
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + mov[i][0];
            int ny = cur.y + mov[i][1];
            if (nx < 1 || nx > 5 || ny < 1 || ny > 5)
                continue;
            string nxs = cur.stu;
            // swap(nxs[(cur.x - 1) * 5 + cur.y - 1], nxs[(nx - 1) * 5 + ny -
            // 1]);
            int targeta = (cur.x - 1) * 5 + cur.y - 1;
            int targetb = (nx - 1) * 5 + ny - 1;
            char tps = nxs[targeta];
            nxs[targeta] = nxs[targetb];
            nxs[targetb] = tps;
            if (onemp[nxs] != 0 && !twomp[nxs]) {
                printf("%d\n", onemp[nxs] - 1 + onemp[cur.stu]);
                return;
            }
            if (!twomp[nxs]) {
                onemp[nxs] = onemp[cur.stu] + 1;
                q.push(xf(nx, ny, nxs));
                twomp[nxs] = true;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        onemp.clear();
        string maps;
        int sx, sy;
        for (int i = 1; i <= 5; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < 5; j++) {
                if (tmp[j] == '*')
                    sx = i, sy = j + 1;
            }
            maps += tmp;
        }
        if (!onebfs(maps, sx, sy))
            twobfs(3, 3, aim);
    }
    return 0;
}
