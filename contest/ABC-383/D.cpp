#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll maxn = 2e6 + 10;
bool np[maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    np[0] = np[1] = true;
    ll n; cin >> n;
    vector<ll> prime;
    for(ll i = 2; i <= ll(2e6); i++) {
        if(!np[i]) {
            prime.push_back(i);
            for(ll j = i * i; j <= ll(2e6); j += i){
                np[j] = true;
            }
        }
    }
    // a^2 * b^2
    ll ans = 0;
    for(size_t i = 0; i < prime.size() - 1; i++) {
        ll t = prime[i];
        if(t * t * t * t > n) break;
        if(t <= 100 && t * t * t * t * t * t * t * t <= n) ans++;
        for(size_t j = i + 1; j < prime.size(); j++) {
            if(prime[i] * prime[i] * prime[j] * prime[j] <= n) ans++;
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}
