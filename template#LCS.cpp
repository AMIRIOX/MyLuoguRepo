#include <iostream>
#include <cstdio>
//#define int long long
#define INF 0x7fffffff
using namespace std;
const int maxn = 1e3+1;
int a[maxn],b[maxn],f[maxn/2][maxn/2];
int ans=-INF;
signed main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            // calc f[i][j];
            //*  f[i][j]=
            /*
            ?    a[i]=b[j]: f[i-1][j-1]+1
            ?    a[i]!=b[j]: max(f[i-1][j],f[i][j-1])
            */
           if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
           else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    cout << f[n][n];
    return 0;
}