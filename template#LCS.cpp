#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e5+1;
int a[maxn],b[maxn],ans=-INF,f[maxn][maxn];
signed main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) {
        f[0][i]=0;
        f[i][0]=0;
    }
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=n;j++) {
            // calc f[i][j];
            //*  f[i][j]=
            /*
            ?    a[i]=b[j]: f[i-1][j-1]+1
            ?    a[i]!=b[j]: max(f[i-1][j],f[i][j-1])
            */
           if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
           else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    
    return 0;
}