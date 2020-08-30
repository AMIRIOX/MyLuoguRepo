#include <iostream>
#include <vector>
#define re register
using namespace std;
const int maxn = 10010;

// struct edge {
//     int to;
//     int dis;
//     edge(int t = 0, int d = 0) : to(t), dis(d) {}
// };
int gr[maxn][maxn];
int ways[maxn];
const int inf = 0x7fffffff;
int ans;

int main() {
    int n, m;
    cin >> n >> m;
    
    // initialize
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) gr[i][j] = inf;
        }
    }

    // inputs
    for (int i = 1; i <= m; i++) {
        cin >> ways[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            gr[i][j] = x;
        }
    }

    // floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (gr[i][j] > gr[i][k] + gr[k][j]) {
                    gr[i][j] = gr[i][k] + gr[k][j];
                }
            }
        }
    }
    for(int i=2;i<=m;i++) {
        ans+=gr[ways[i-1]][ways[i]];
    }
    cout << ans;
    return 0;
}