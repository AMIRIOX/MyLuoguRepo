#include <cstdio>
#include <iostream>
#include <queue>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int x = 0, y = 0;
int n, a[maxn][maxn];
int mov[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
struct coord {
    int x, y;
    coord(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    coord(const coord& c) {
        this->x = c.x;
        this->y = c.y;
    }
};
void bfs() {
    queue<coord> q;
    bool isStart=true;
    q.push(coord(x, y));
    while (!q.empty()) {
        coord curd = q.front();
        q.pop();
        if(curd.x==x && curd.y==y && !isStart){
            
            break;
        }
        isStart=false;
        for (int i = 0; i < 4; i++) {
            int ux = curd.x + mov[i][0];
            int uy = curd.y + mov[i][1];
            if(ux==1 && uy==1) q.push(coord(ux,uy));
        }
    }
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                x = i, y = j;
                bfs();
                break;
            }
        }
    }
    return 0;
}