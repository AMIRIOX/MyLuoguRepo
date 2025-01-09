#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll int_pow(ll a, ll t) {
    ll res = 1;
    for (int i = 0; i < t; i++) res *= a;
    return res;
}

ll count(ll r) {
    vector<int> digit;
    while (r) {
        digit.push_back(r % 10);
        r /= 10;
    }
    reverse(digit.begin(), digit.end());
    int n = digit.size();
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            res++;
            break;
        }
        res += int_pow(digit[0], n - 1 - i) * min(digit[0], digit[i]);
        if (digit[i] >= digit[0]) break;
    }
    for (int i = 0; i < n; i++) {
        int mx = (i ? 9 : digit[0] - 1);
        for (int j = 1; j <= mx; j++) {
            res += int_pow(j, n - 1 - i);
        }
    }
    return res;
}

int main() {
    ll l, r;
    cin >> l >> r;
    cout << count(r) - count(l - 1) << endl;
}

