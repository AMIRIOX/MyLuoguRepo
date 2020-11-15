#include <iostream>
#include <utility>
#define pa pair<int, int>
using namespace std;
const size_t maxn = 1e3;
const int inf = (0x3f3f3f3f);
int gh[maxn][maxn], n, k, s[2000];
pa st[maxn][maxn];
int main() {
  cin >> n >> k;

  // Init
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j)
        gh[i][j] = inf;
    }
  }

  for (int i = 1; i <= k; i++) {
    cin >> s[i];
    for (int j = 1; j <= s[i]; j++) {
      cin >> st[i][j].first >> st[i][j].second;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j < s[i]; j++) {
      pa cur = st[i][j];
      for (int y = j; y <= s[i]; y++) {
        gh[cur.first][st[i][y].first] = cur.second + st[i][y].second;
        gh[st[i][y].first][cur.first] = cur.second + st[i][y].second;
      }
    }
  }
  cout << endl;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) {
      //if(gh[i][j]) cout << i << " to " << j << " is "<< gh[i][j] << endl;
      if(i==j) gh[i][j]=0;
    }
  // Floyd test
  for (int t = 1; t <= n; t++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        //if (gh[i][t] != inf && gh[t][j] != inf && gh[i][j] != inf) {
        // if(t==2 && i==1 && j==3) {
        //   cout << gh[i][t] << " " << gh[t][j] << " " << gh[i][j] << endl;
        // }
        if (gh[i][t] + gh[t][j] < gh[i][j]) {
          gh[i][j] = gh[i][t] + gh[t][j];
        }
        //}
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    // cout << "the distance between 1 and " << i << " is " << gh[1][i] << " "
    //      << endl;
    cout << gh[1][i] << " ";
  }
  return 0;
}
