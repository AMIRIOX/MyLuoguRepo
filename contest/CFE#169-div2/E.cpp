#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll N = 1e7;

int ip[N + 10];
vector<int> prime;

void euler() {
    for (int i = 2; i <= N; i++)
        ip[i] = 1;
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (ip[i]) {
            prime.push_back(i);
            ip[i] = ++cnt;
        }
        for (int prij : prime) {
            if (i * prij > N)
                break;
            ip[i * prij] = 0;
            if (i % prij == 0)
                break;
        }
    }
}

ll sg[N + 10];

ll SG(ll x) {
    if (sg[x]) return sg[x];

    if (x % 2 == 0) return sg[x] = 0;

    if (ip[x]) return sg[x] = ip[x];

    for (int prij : prime) {
        if (x % prij == 0)
            return sg[x] = SG(prij);
    }
    assert(0);
    return -1;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;

    ll sgsum = 0;
    for(auto &i : a) {
        sgsum ^= SG(i);
    }
    cout << (sgsum ? "Alice" : "Bob") << '\n';
    // SG(a0) ^ SG(a1) ^ ... ^ SG(an-1) != 0
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    euler();
    sg[1] = 1;

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
