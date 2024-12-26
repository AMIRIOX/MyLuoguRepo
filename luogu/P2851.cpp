#include <iostream>
#include <cstring>
// #define int long long
using namespace std;
const int maxn=1e5+10;
int cdp[maxn],mdp[maxn];
int n,t,vs[maxn],cs[maxn];
signed main() {

  // 将n个物品装入容量为T的背包
  // 重量为vs 价值为个数
  // cin >> n >> t;
  scanf("%d %d", &n, &t);
  int sum = 0;
  int vmf=0;
  for(int i=1;i<=n;i++) scanf("%d",&vs[i]);
  for(int i=1;i<=n;i++) {
    // cin >> cs[i];
    scanf("%d", &cs[i]);
    sum+=vs[i]*cs[i];
    vmf=max(vmf,vs[i]*vs[i]);
  }
  if(sum<t) {
    cout << "-1";
    return 0;
  }
  // vmf=vmf*vmf;
  // 跑一次完全背包: 数目无限 老板的找钱
  memset(cdp,0x3f,sizeof(cdp));
  cdp[0]=0;
  for(int i=1;i<=n;i++) {
    for(int j=vs[i]; j<=vmf; j++) {
      cdp[j]=min(cdp[j],cdp[j-vs[i]]+1);
    }
  }

  // 跑一次多重背包: 数目有限 john的付钱
  memset(mdp,0x3f,sizeof(mdp));
  mdp[0]=0;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=cs[i];j<<=1) {
      for(int k=t+vmf;k>=j*vs[i];k--) {
        mdp[k]=min(mdp[k],mdp[k-j*vs[i]]+j);
      }
      cs[i]-=j;
    }
    if(cs[i]) {
      for(int k=t+vmf;k>=cs[i]*vs[i];k--) {
        mdp[k]=min(mdp[k],mdp[k-cs[i]*vs[i]]+cs[i]);
      }
    }
  }

  int ans = 0x3f3f3f3f;
  for(int i=t;i<=t+vmf;i++) {
    ans=min(ans,mdp[i]+cdp[i-t]);
  }

  if(ans<0x3f3f3f3f) printf("%d",ans);
  else printf("-1");
  // printf("%d\n",ans>=0x3f3f3f3f?-1:ans);

  return 0;
}
