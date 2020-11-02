#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;
int n, have[maxn], minx = INF, maxx = -INF, ans, anst;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < minx) minx = x;
        if (x > maxx) maxx = x;
        have[x]++;
    }
    for (int i = 1; i <= maxx; i++) {
        // // i=i=(j+k)
        //* (i+j)=x1=x2, have[x]>=2
        for (int j = i; j <= maxx; j++) {
            if (i == j) {
                anst++;
                continue;
            }
            if(have[i+j]>=2) ans++;
        }
    }
    ans+=(anst/2);
    cout << ans % mod << endl;
    return 0;
}