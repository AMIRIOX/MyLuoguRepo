#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;
const int mod = (1e9 + 7);
int n, have[maxn], maxx = -INF, ans;
int C2(int x) { return ((x * x - x) / 2) % mod; }
signed main() {
    int x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x > maxx) maxx = x;
        have[x]++;
    }
    for (int i = 1; i <= maxx; i++) {
        // // i=i=(j+k)
        //* (i+j)=x1=x2
        for (int j = i; j <= maxx; j++) {
            if (i == j)
                ans = (ans + C2(have[i]) * C2(have[i + j])) % mod;
            else
                ans = (ans + C2(have[i]) * C2(have[j]) % mod * C2(have[i + j]) %
                                 mod) %
                      mod;
        }
    }
    cout << ans << endl;
    return 0;
}