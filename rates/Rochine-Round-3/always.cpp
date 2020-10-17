#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800
using namespace std;
const int maxn = 1e6+1;
int ans = -INF;
signed main() {
    int n;
    cin >> n;
    for(int a=1;a<=n;a++) {
        for(int b=1;b<=n;b++) {
            ans=max(ans,(a | b)+(a ^ b));
        }
    }
    cout << ans;
    return 0;
}