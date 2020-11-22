#include <iostream>
using namespace std;
const int maxn =1e7+10;
#define int long long
int dp[maxn],n,w,c[maxn],v[maxn];
signed main() {
  cin >> w >> n;
  for(int i=1;i<=n;i++) {
    cin >> c[i] >> v[i];
  }
  for(int i=1;i<=n;i++) {
    for(int j=0;j<=w;j++) {
      if(j>=c[i]) dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
    }
  }
  cout << dp[w];
  return 0;
}
