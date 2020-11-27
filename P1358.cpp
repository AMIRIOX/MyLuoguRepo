#include <iostream>
using namespace std;
const int maxn = 1e4+10;
const int mod = 10007;
int a[maxn], n, m, f[maxn][maxn];
int main() {
  cin >> n >> m;
  for(int i=1;i<=m;i++) cin >> a[i];
  cout << "?" << endl;
  //m个物品装到容量为n的背包, 求正好放进去有几种做法
  for(int i=1;i<=m;i++) {
    for(int j=1;j<=n;j++) {
      if(j==a[i]) f[i][j]=f[i-1][j]+1;
      if(j<a[i]) f[i][j]=f[i-1][j];
      if(j>a[i]) f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
    }
  }
  cout << f[m][n];
  return 0;
}
