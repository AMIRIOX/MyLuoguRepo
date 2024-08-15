#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &ai: a) cin >> ai;
    sort(a.begin(), a.end(), greater<int>());
    vector<int> gaps(n);
    int fstgap = 0;
    for(int i = 1; i < n; i += 2) {
        fstgap += (a[i - 1] - a[i]);
        gaps.push_back(a[i - 1] - a[i]);
        if(i == n - 2) {
            fstgap += a[n-1];
            break;
        } 
    }
    sort(gaps.begin(), gaps.end(), greater<int>());
    for(int i = 0; i < gaps.size(); i++) {
        if(gaps[i] <= k) {
            k -= gaps[i];
            fstgap -= gaps[i];
        }else {
            fstgap -= k;
            break;
        }
    }
    cout << fstgap << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}

