#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

int tmp;
void solve() {
    unordered_map<int, int> bib;
    unordered_map<int, int> point;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        point[i + 1] = tmp;
    }

    vector<int> wear;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        wear.push_back(tmp);
        bib[tmp] = i + 1;
    }
    
    for(int i = 0; i < n; i++) {
        cout << wear[point[bib[i + 1]] - 1] << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

