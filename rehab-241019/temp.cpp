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
    
}
signed main() {
    int n;
    /*
 0123456
0xxxxxxx
1x /\
2x/__\
 /\  /\
/__\/__\
     */

    base_set(1, 2);
    for(int i = 1; i <= 4; i++) { 
        for(int j = 1; j <= 4; j++)
            print(ans[i][j])
        cout << endl;
    }
    return 0;
}
