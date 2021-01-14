#include <iostream>
using namespace std;
int G[5000][5000];
int s, e, n, m, b;
const int meta = 1;
int main(void)
{
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        G[x][y] = min(G[x][y], v);
        G[y][x] = min(G[y][x], v);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
    for (int i = 1; i <= b; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", G[x][1] + G[1][y]);
    }
    return 0;
}