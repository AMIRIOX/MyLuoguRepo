#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll in) {
    string str = to_string(in);
    const int n = str.size();
    vector mem(n + 1, vector<ll>(10, -1));
    auto dfs = [&](auto &&self, int p, bool limit, bool lead, int fst) -> ll {
        if(p == n) return !lead;
        if(!limit && !lead && ~mem[p][fst]) return mem[p][fst];
        
        ll ans = 0;
        // snake number: d1 > d[2~n]
        int up = (limit ? str[p] - '0' : 9);
        for(int i = 0; i <= up; i++) {
            if(!lead) {
                if(i < fst)
                    ans += self(self, p + 1, limit and i == up, lead && i == 0, fst);
            }else {
                if(i == 0) 
                    ans += self(self, p + 1, limit and i == up, lead && i == 0, fst);
                else 
                    ans += self(self, p + 1, limit and i == up, lead && i == 0, i);
            }
        }

        if(!limit && !lead) mem[p][fst] = ans;
        return ans;
    };

    return dfs(dfs, 0, true, true, 0);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    ll l, r; cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;
    return 0;
}
