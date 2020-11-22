#include <iostream>
#include <cstdio>
#define int long long
#define LLONG_MAX 9223372036854775807
using namespace std;
const int maxn = 1e6+10;
const int inf = LLONG_MAX;
int n, k;
int a[maxn],fdis[maxn];
int ans=inf;
signed main() {
  scanf("%lld %lld", &n, &k);
  for(int i=2;i<=n;i++) {
    scanf("%lld", &a[i]);
    a[i]+=a[i-1];
  }
  // // (1)__1__(2)__2__(3)__3__(4)__4__(5)
  // // (实际意义)
  // // [i=2,k=2] 1->i ~ i+k->n
  // // i+1 -> i+k
  // // (1)____a[1]____(2)
  // // 计算1->n
  // int sum = 0;
  // for(int i=1;i<n;i++) {
  //   sum+=a[i];
  // }
  // for(int i=1;i<n;i++) {
  //     int insum=0;
  //     for(int j=i;j<=i+k-1;j++) {
  //       insum+=a[i];
  //     }
  //     if(sum>=insum) ans=min(ans,sum-insum);
  // }

  // // 前缀和储存1->i, i->n
  // for(int i=1;i<n;i++) {
  //   fdis[i]=fdis[i-1]+a[i];
  // }
  // for(int i=n-1;i>=1;i--) {
  //   edis[i]=edis[i+1]+a[i];
  // }
  // for(int i=1;i<n;i++) {
  //
  // }
  for(int i=1;i<=n;i++) {
    fdis[i]=a[i]+(a[n]-a[i+k]);
  }
  for(int i=1;i<=n;i++) {
    ans=min(ans,fdis[i]);
  }
  printf("%lld", ans);
  return 0;
}
