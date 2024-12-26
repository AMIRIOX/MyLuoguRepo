#include <cstdio>
#include <iostream>
using namespace std;
char source[120][120], dest[120][120];
string tgt = "yizhong";
int n;
int wk[8][2] = {{0, 1},  {1, 0},   {1, 1},  {-1, 0},
                {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
char beat_against_rubbish_getchar() {
    char ch=getchar();
    while(ch==' ' || ch=='\n' || ch=='\r') ch=getchar();
    return ch;
}
bool dfs(int ind, int x, int y, int dirx, int diry) {
    if (ind == 6 && source[x][y] == tgt[ind]) {
        dest[x][y] = tgt[ind];
        return true;
    }
    int nx = x + dirx, ny = y + diry;
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n &&
        source[nx][ny] == tgt[ind + 1])
        if (dfs(ind + 1, nx, ny, dirx, diry)) {
            dest[x][y] = tgt[ind];
            return true;
        }

    return false;
}
int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            source[i][j]=beat_against_rubbish_getchar();
            dest[i][j] = '*';
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (source[i][j] == tgt[0]) {
                for (int fx = 0; fx < 8; fx++) {
                    dfs(0, i, j, wk[fx][0], wk[fx][1]);
                }
            }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", dest[i][j]);
        }
        printf("\n");
    }
    return 0;
}