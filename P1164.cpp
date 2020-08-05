#include <iostream>
using namespace std;
int n, m, a[1001],f[1001][1001],ans;
// void dfs(int sum,int i) {
//     if(i==n){
//         if(sum==m) ans++;
//         return;
//     } 
//     dfs(sum+a[i],i+1);
//     dfs(sum,i+1);
// }
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==a[i]) f[i][j]=f[i-1][j]+1;
            if(j<a[i]) f[i][j]=f[i-1][j];
            if(j>a[i]) f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
        }
    }
    //dfs(0,0);
    cout << (ans = f[n][m]);
    return 0;
}