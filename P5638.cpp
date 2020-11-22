#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 1e6+10;
const int inf = 0x7fffffff;
int n, a[maxn], k, ans=inf;
signed main() {
  scanf("%lld %lld", &n, &k);
  for(int i=1;i<n;i++) {
    scanf("%lld", &a[i]);
  }
  // (1)__1__(2)__2__(3)__3__(4)__4__(5)
  // (实际意义)
  // [i=2,k=2] 1->i ~ i+k->n
  // i+1 -> i+k
  // (1)____a[1]____(2)


  // 计算1->n
  int sum = 0;
  for(int i=1;i<n;i++) {
    sum+=a[i];
  }
  for(int i=1;i<n;i++) {
      int insum=0;
      for(int j=i;j<=i+k-1;j++) {
        insum+=a[i];
      }
      if(sum>=insum) ans=min(ans,sum-insum);
  }
  printf("%lld", ans);
  return 0;
}
