#include <bits/stdc++.h>
using namespace std;
string solve(int a, int b, int k) {
    if (/*a >= 1 && b >= 1 && !k*/ a + b - 1 < k) {
        return "-1";
    } else if (!a && !b && !k) {
        return "-1";
    }

    int flg[2] = {a, b};
    string ans;

    auto test = [&](int bit) {
        for (int i = 1; i <= k; i++) {
            if (flg[1 - bit] <= 0) {
                return -1;
            }
            ans += (bit = 1 - bit) + '0';
            flg[bit]--;
        }
        if (flg[bit] && !flg[1 - bit])
            return -1;
        return bit;
    };

    int bit = 0;
    if ((bit = test(1)) != -1) {
        while (flg[bit] > 0) {
            ans += bit + '0';
            flg[bit]--;
        }
        while (flg[1 - bit] > 0) {
            ans += 1 - bit + '0';
            flg[1 - bit]--;
        }
        return ans;
    }

    flg[0] = a;
    flg[1] = b;
    ans = "";
    if ((bit = test(0)) != -1) {
        while (flg[bit] > 0) {
            ans += bit + '0';
            flg[bit]--;
        }
        while (flg[1 - bit] > 0) {
            ans += 1 - bit + '0';
            flg[1 - bit]--;
        }
        return ans;
    }
    return "-1";
}

using i64 = long long;
const int N = 1e6 + 10;
const int mod = 998244353;
#define endl '\n'
bool flag = false;
int cnt = 0;
#define all(x) x.begin(), x.end()
// int xx[] = { 1,0,-1,0 };
// int yy[] = { 0,1,0,-1 };
i64 qp(i64 a, i64 b) {
    i64 res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

string solve_right(int a, int b, int k) {
    // x x+1 x*2
    string t;
    auto o1 = [&](char x, char y, int a, int b) {
        t += y;
        b--;
        for (int i = 0; i < k / 2; i++) {
            t += x;
            t += y;
            a--, b--;
        }
        if (a) {
            t.pop_back();
            b++;
            t += string(a, x);
        }
        t += string(b, y);
    };
    if (k % 2 == 0) {
        if (k == 0) {
            if (min(a, b) == 0) {
                t = string(a, '0') + string(b, '1');
            }
        } else if (a >= k / 2 && b >= k / 2 + 1) {
            o1('0', '1', a, b);
        } else if (b >= k / 2 && a >= k / 2 + 1) {
            o1('1', '0', b, a);
        }
    } else {
        int ned = (k + 1) / 2;
        if (a >= ned && b >= ned) {
            for (int i = 0; i < ned; i++) {
                t += '0';
                t += '1';
                a--, b--;
            }
            if (a) {
                t.pop_back();
                b++;
                t += string(a, '0');
            }
            t += string(b, '1');
        }
    }
    if (t.empty())
        t = "-1";
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    constexpr int MAX_VAL = 100;
    int a, b, k;
    while(1) {
        a = rand() % MAX_VAL;
        b = rand() % MAX_VAL;
        k = rand();
        if ((a + b))
            k = k % (a + b);
        if(solve(a, b, k) != solve_right(a, b, k)) break;
    }
    cout << a << " " << b << " " << k << '\n';
    cout << solve(a, b, k) << " " << solve_right(a, b, k) << '\n';
    return 0;
}

