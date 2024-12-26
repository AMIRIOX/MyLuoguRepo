#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 3e5;
int n,a1[maxn],b1[maxn],a[maxn], b[maxn], ans;
int main() {
  cin >> n;
  for(int i=1;i<=n;i++) {
    if(i%2==0) cin >> b[i];
    else cin >> a[i];
  }
  // 1. 把输入分成两个数组a[]和b[]
  // 如果是1 5 3 6 5, 则分为
  //     1 0 3 0 5
  //     0 5 0 6 0
  // 2. 分别计算两个数组的前缀和
  // 3. 枚举每一个区间, 计算对应区间两个前缀和, 计算绝对值
  // 4. 更新答案
  // int ld, rd;
  for(int i=1;i<=n;i++) a1[i]=a1[i-1]+a[i];
  for(int i=1;i<=n;i++) b1[i]=b1[i-1]+b[i];
  for(int i=1;i<=n;i++) {
    for(int j=i;j<=n;j++) {
      int x = a1[j]-a1[i-1];
      int y = b1[j]-b1[i-1];
      int res = abs(x-y);
      if(i==j) res=a[i];
      if(res>ans) {
        // ld=i,rd=j;
        ans=res;
      }
      // ans=max(ans,res);
    }
  }
  // cout << ld << " " << rd << endl;
  cout << ans;
  return 0;
}
