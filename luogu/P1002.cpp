#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
int f[50][50];
int bx, by, hx, hy;
int r[50][50];
signed main() {
    scanf("%lld%lld%lld%lld", &bx, &by, &hx, &hy);
    //* r[i][j]=r[i-1][j]+r[i][j-1]
    f[hx][hy] = 1;
    if(hx - 1>=0 && hy + 2>=0) f[hx - 1][hy + 2] = 1;
    //cout << "vic1";
    if(hx - 2>=0 && hy + 1>=0) f[hx - 2][hy + 1] = 1;
    //cout << "vic2";
    if(hx - 2>=0 && hy - 1>=0) f[hx - 2][hy - 1] = 1;
    //cout << "vic3";
    if(hx - 1>=0 && hy - 2>=0) f[hx - 1][hy - 2] = 1;
    //cout << "vic4";
    if(hx + 1>=0 && hy - 2>=0) f[hx + 1][hy - 2] = 1;
    //cout << "vic5";

    if(hx + 2>=0 && hy - 1>=0) f[hx + 2][hy - 1] = 1;
    //cout << "vic6";

    f[hx + 2][hy + 1] = 1;
    //cout << "vic7";

    f[hx + 1][hy + 2] = 1;
    //cout << "vic8";


    r[0][0] = 1;
    if (hx == 0 && hy == 0) {
        cout << 0;
    } else {
        for (int x = 0; x <= bx; x++) {
            for (int y = 0; y <= by; y++) {
                if (f[x][y]) continue;
                if (x) r[x][y] += r[x - 1][y];
                if (y) r[x][y] += r[x][y - 1];
            }
        }
    }
    cout << r[bx][by];
    // system("pause");
    return 0;
}