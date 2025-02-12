#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define push push_back
#define pop pop_back
#define top back

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<int> inc(n);
    vector<int> dec(n);

    vector<int> s;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(s.begin(), s.end(), a[i]);
        if (it == end(s))
            s.push(a[i]);
        else
            *it = a[i];
        inc[i] = i + 1 - s.size();
    }

    vector<int>().swap(s);
    s.reserve(n);
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(s.begin(), s.end(), a[i]);
        if (it == end(s))
            s.push(a[i]);
        else 
            *it = a[i];
        dec[n - i - 1] = i + 1 - s.size();
    }

    int ans = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        ans = min(ans, inc[i] + dec[i]);
    }
    cout << ans << '\n';
}
