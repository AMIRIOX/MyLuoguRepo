#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e4+1;
int f[maxn][maxn],ans=-INF;
signed main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin >> f[i][j];
            f[i][j]+=max(f[i-1][j],f[i-1][j-1]);
            ans=max(ans,f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}