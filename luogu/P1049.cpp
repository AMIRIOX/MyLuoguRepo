#include <iostream>
using namespace std;
const int maxn = 20010;
int dp[maxn],n,c[maxn],V;
int main() {
  cin >> V >> n;
  for(int i=1;i<=n;i++) {
    cin >> c[i];
  }
  for(int i=1;i<=n;i++) {
    for(int j=V;j>=0;j--) {
      if(j>=c[i]) dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
    }
  }
  cout << V-dp[V];
  return 0;
}
