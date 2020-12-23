#include <iostream>
using namespace std;
int a[200][200], sum[200][200], ans;
int n, tot;
int ctp(int x1, int y1, int x2, int y2) {
    /*
0 -2 -7 0
 9 2 -6 2
-4 1 -4  1 
-1 8  0 -2
    */
    return sum[x2][y2]-sum[x1-1][y2]+sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main() {
/* 二维前缀和
    array a[], i, j, n, m
    for(int i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
*/
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    tot = sum[n][n];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            // 枚举: (i,j) 为左上角端点
            for(int k=i; k<=n; k++) {
                for(int l=j; l<=n; l++) {
                    // 枚举: (k,l) 为右下角端点
                    if((i==k && j==l) || (k==l)) continue;
                    ans = max(ans, ctp(i,j,k,l));
                    if(ctp(i,j,k,l)==24){
                        cout << i << " " << j << " " << k << " " << l << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}