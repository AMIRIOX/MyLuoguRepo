#include <iostream>
using namespace std;
const int maxn = 3e5+10;
int W,n,v[maxn],w[maxn];
int dp[maxn];
int main() {
  cin >> W >> n;
  int dex=0;
  for(int i=1;i<=n;i++) {
    cin >> w[i] >> v[i];
    v[i]=(v[i]*w[i]);
  }
  for(int i=1;i<=n;i++) {
    for(int j=W;j>=0;j--) {
      if(j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
  }
  cout << dp[W];
  return 0;
}
