#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
char ans[maxn][maxn];

#define print(x) do{ cout << (x ? x : ' '); } while(0);

void base_set(int x, int y) {
    ans[x][y] = '/';
    ans[x][y + 1] = '\\';
    ans[x + 1][y - 1] = '/';
    ans[x + 1][y] = ans[x + 1][y + 1] = '_';
    ans[x + 1][y + 2] = '\\';
}

void solve(int n, int x, int y) {
    if(n == 1) {
        base_set(x, y);
    }else {
        int curh = 2 * (1 << (n - 1));
        int curw = 4 * (1 << (n - 2));
        solve(n - 1, x, y);
        solve(n - 1, x + curh / 2, y - curw / 2);
        solve(n - 1, x + curh / 2, y + curw / 2);
    }
}
signed main() {
    int n;
    cin >> n;
    int h = 2 * (1 << (n - 1));
    int w = 4 * (1 << (n - 1));
    solve(n, 1, w / 2);
    for(int i = 1; i <= h; i++) { 
        for(int j = 1; j <= w; j++)
            print(ans[i][j])
        cout << endl;
    }
    return 0;
}
