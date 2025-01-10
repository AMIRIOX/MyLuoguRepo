#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    
    long long ans = 1e18;
    
    auto upd = [&](vector<long long> a) {
      sort(a.begin(), a.end());
      for (int i = 1; i < (int)a.size(); ++i)
        if (a[i - 1] == a[i]) return;
      long long res = 0;
      for (int i = 0; i < (int)a.size(); i += 2)
        res = max(res, a[i + 1] - a[i]);
      ans = min(ans, res);
    };
    
    if (n % 2 == 0) {
      upd(a);
      cout << ans << '\n';
      continue;
    }
    
    for (int i = 0; i < n; ++i) {
      for (int x : {-1, 1}) {
        a.push_back(a[i] + x);
        upd(a);
        a.pop_back();
      }
    }
    
    cout << ans << '\n';
  }
}
