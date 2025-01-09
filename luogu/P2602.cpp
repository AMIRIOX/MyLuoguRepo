#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 返回 [1, r] 中某数位出现的次数
// 依次填每一位, 利用 limit 和 lead 限制小于上界
// limit 的处理方式: 若 limit 则 up 是 int(str[p]) 否则才为 9
// lead 的处理方式: 如果 lead 且 i ==0 则不计入答案.
ll solve(ll in, int dig) {
    string str = to_string(in);
    const int n = str.size();
    vector mem(n + 1, vector<ll>(n + 1, -1));

    auto dfs = [&](auto&& self, int p, bool limit, bool lead, int sum) -> ll {
        if(p == n) return sum;
        if(!limit && !lead && ~mem[p][sum]) return mem[p][sum]; 
        ll ans = 0;

        int up = (limit ? str[p] - '0' : 9);
        for(int i = 0; i <= up; i++) {
            if(lead && i == 0) {
                ans += self(self, p + 1, limit && i == up, lead && i == 0, sum);
            }else {
                ans += self(self, p + 1, limit && i == up, lead && i == 0, sum + (i == dig));
            }
        }

        if(!limit && !lead) mem[p][sum] = ans;
        return ans;
    };

    return dfs(dfs, 0, true, true, 0);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    ll l, r;
    cin >> l >> r;
    for(int i = 0; i <= 9; i++) cout << solve(r, i) - solve(l - 1, i) << ' ';
    endl(cout);
    return 0;
}
