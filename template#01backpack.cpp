#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e3+1;
int v[maxn],w[maxn],n,weight,f[maxn][maxn];
int main() {
    cin >> weight >> n;
    for(int i=1;i<=n;i++) {
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=0; j<=weight; j++) {
            if(j>=w[i]) f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
            else f[i][j] = f[i-1][j];
        }
    }
    cout << f[n][weight];
    return 0;
}
