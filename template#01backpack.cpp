#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e3+1;
int v[maxn], w[maxn], n, weight, f[maxn][maxn], dp[maxn];
int main() {
    cin >> weight >> n;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }

    // 普通
    if(false) { 
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= weight; j++) {
                if(j >= w[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
                else f[i][j] = f[i - 1][j];
            }
        }
    }

    // 压维
    for(int i = 1; i <= n; i++) {
        for(int j = weight; j >= 0; j--) {
            if(w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            if(i==n && j==0) break;
        }
    }

    // cout << f[n][weight];
    //
    cout << dp[weight] << endl;
    return 0;
}
