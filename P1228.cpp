#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 12200;
int filled[maxn][maxn];
int k, x, y;
void dog(int _x, int _y, int n, int gx, int gy) {
    // 思路：
    /*
        如果当前方块是2*2的，把没填的那三个填好
        否则分成四个小方块，把没有公主的三个方块靠近中心点的格子铺上,
        将铺上的格子作为公主格子继续递归分治
    */
    if (n == 2) {
        if (filled[_x][_y]) {
            printf("%d %d %d\n", _x + 1, _y, 1);
            printf("%d %d %d\n", _x, _y + 1, 1);
            printf("%d %d %d\n", _x + 1, _y + 1, 1);
        } else if (filled[_x + 1][_y]) {
            printf("%d %d %d\n", _x, _y, 2);
            printf("%d %d %d\n", _x, _y + 1, 2);
            printf("%d %d %d\n", _x + 1, _y + 1, 2);

        } else if (filled[_x][_y + 1]) {
            printf("%d %d %d\n", _x, _y, 3);
            printf("%d %d %d\n", _x + 1, _y, 3);
            printf("%d %d %d\n", _x + 1, _y + 1, 3);
        } else {
            printf("%d %d %d\n", _x, _y, 4);
            printf("%d %d %d\n", _x + 1, _y, 4);
            printf("%d %d %d\n", _x, _y + 1, 4);
        }
        return;
    }
    if (gx <= _x + n / 2 && gy <= _y + n / 2) {  // TODO
        filled[_x + n / 2 + 1][_y + n / 2] = 1;
        printf("%d %d %d\n", _x + n / 2 + 1, _y + n / 2, 1);
        filled[_x + n / 2][_y + n / 2 + 1] = 1;
        printf("%d %d %d\n", _x + n / 2, _y + n / 2 + 1, 1);
        filled[_x + n / 2 + 1][_y + n / 2 + 1] = 1;
        printf("%d %d %d\n", _x + n / 2 + 1, _y + n / 2 + 1, 1);
        dog(_x, _y, n / 2, gx, gy);
        dog(_x + n / 2, _y, n / 2, _x + n / 2 + 1, _y + n / 2);
        dog(_x, _y + n / 2, n / 2, _x + n / 2, _y + n / 2 + 1);
        dog(_x + n / 2, _y + n / 2, n / 2, _x + n / 2 + 1, _y + n / 2 + 1);
    } else if (gx > _x + n / 2 && gy <= _y + n / 2) {
        filled[_x + n / 2][_y + n / 2] = 1;
        printf("%d %d %d\n", _x + n / 2, _y + n / 2, 2);
        filled[_x + n / 2][_y + n / 2 + 1] = 1;
        printf("%d %d %d\n", _x + n / 2, _y + n / 2 + 1, 2);
        filled[_x + n / 2 + 1][_y + n / 2 + 1] = 1;
        printf("%d %d %d\n", _x + n / 2 + 1, _y + n / 2 + 1, 2);
        dog(_x, _y, n / 2, _x + n / 2, _y + n / 2);
        dog(_x + n / 2, _y, n / 2, gx, gy);
        dog(_x, _y + n / 2, n / 2, _x + n / 2, _y + n / 2 + 1);
        dog(_x + n / 2, _y + n / 2, n / 2, _x + n / 2 + 1, _y + n / 2 + 1);
    } else if (gx <= _x + n / 2 && gy > _y + n / 2) {
        filled[_x + n / 2][_y + n / 2] = 1;
        printf("%d %d %d\n", _x + n / 2, _y + n / 2, 3);
        filled[_x + n / 2 + 1][_y + n / 2] = 1;
        printf("%d %d %d\n", _x + n / 2 + 1, _y + n / 2, 3);
        filled[_x + n / 2 + 1][_y + n / 2 + 1] = 1;
        printf("%d %d %d\n", _x + n / 2 + 1, _y + n / 2 + 1, 3);
        dog(_x, _y, n / 2, _x + n / 2, _y + n / 2);
        dog(_x + n / 2, _y, n / 2, _x + n / 2 + 1, _y + n / 2);
        dog(_x, _y + n / 2, n / 2, gx, gy);
        dog(_x + n / 2, _y + n / 2, n / 2, _x + n / 2 + 1, _y + n / 2 + 1);

    } else {
        filled[_x + n / 2][_y + n / 2] = 1;
        printf("%d %d %d\n", _x + n / 2, _y + n / 2, 1);
        filled[_x + n / 2 + 1][_y + n / 2] = 1;
        printf("%d %d %d\n", _x + n / 2 + 1, _y + n / 2, 1);
        filled[_x + n / 2][_y + n / 2 + 1] = 1;
        printf("%d %d %d\n", _x + n / 2, _y + n / 2 + 1, 1);
        dog(_x, _y, n / 2, _x + n / 2, _y + n / 2);
        dog(_x + n / 2, _y, n / 2, _x + n / 2 + 1, _y + n / 2);
        dog(_x, _y + n / 2, n / 2, _x + n / 2, _y + n / 2 + 1);
        dog(_x + n / 2, _y + n / 2, n / 2, gx, gy);
    }
}
signed main() {
    scanf("%d %d", &k, &x, &y);
    filled[x][y] = 1;
    dog(1, 1, (int)pow(2, k), x, y);
    return 0;
}