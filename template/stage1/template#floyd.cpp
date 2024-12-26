#include <iostream>
#include <vector>
#define re register
using namespace std;
const int maxn = 1000;
const int infinity = 99999999;
int gr[maxn][maxn];
int n, m;
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (gr[i][j] > gr[i][k] + gr[k][j]) {
                    gr[i][j] = gr[i][k] + gr[k][j];
                }
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) gr[i][j] = infinity;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        gr[x][y] = z;
    }
    floyd();

    cout << gr[1][5];
    return 0;
}
