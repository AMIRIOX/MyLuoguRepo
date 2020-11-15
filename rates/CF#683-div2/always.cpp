// C

#include <iostream>
#include <numeric>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3+10;
int n,a[maxn],W;
int main() {
  int T;
  while(T--) {
    memset(a,0,sizeof a);
    cin >> n >> W;
    for(int i=1;i<=n;i++) {
      cin >> a[i];
    }
    cout << "ok";
    int sum = accumulate(a+1,a+n+1,0);
    if(sum<(W/2)) cout << -1 << endl;
    else {
      sum = 0;
      sort(a+1,a+n+1);
      for(int i=1;i<=n;i++) {
        if(sum<=(W/2)) {
          sum+=a[i];
        }else {
          if(sum<=W) {
            for(int j=1;j<i;j++) {
              cout << a[j] << " ";
            }
          }
          cout << endl;
          break;
        }
      }
    }
  }
  return 0;
}
