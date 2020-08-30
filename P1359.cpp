#include <cstring>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 10010;
int gr[maxn][maxn];
const int inf = 0x7fffffff;
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) gr[i][j] = inf;

    for (int i = 1; i < n; i++) {
        for (int j = i; j <= n; j++) {
            if(i!=j) cin >> gr[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }
    cout << gr[1][n];
    return 0;
}