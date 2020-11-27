#include <iostream>
using namespace std;
int a[5000],dp[5000][5000];
int vs[5000], _ws[5000];
int main() {
  int maxw,maxv,n;
  cin >> maxv >> maxw;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> vs[i] >> _ws[i] >> a[i];
  }
  for(int i=1;i<=n;i++) {
    for(int j=maxv;j>=0;j--) {
      for(int k=maxw;k>=0;k--) {
        if(j>=vs[i] && k>=_ws[i]) {
          dp[j][k] = max(dp[j][k],dp[j-vs[i]][k-_ws[i]]+a[i]);
        }
      }
    }
  }
  cout << dp[maxv][maxw];
  return 0;
}
