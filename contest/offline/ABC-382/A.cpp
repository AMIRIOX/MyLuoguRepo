#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    ll ept = 0, fill = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '.') ept++;
        else fill++;
    }
    cout << ept + min(fill, k) << endl;
    return 0;
}
