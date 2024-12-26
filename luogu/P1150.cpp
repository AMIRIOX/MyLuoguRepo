#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e5+10;
int n,k,p,ans;
signed main() {
    cin >> n >> k;
    // 4 3
    /*
        4 
        1 3 => 2

    */
    p=n;
    while(p>=k) {
        int tmp = p;
        p %= k;
        ans += ((int)(tmp/k))*k;
        // cout << "xi le " << ((int)(tmp/k))*k << " zhi yan" << endl;
        p += tmp/k;
        // cout << "huan le " << tmp/k << " zhi yan" << endl;
    }
    ans+=p;
    cout << ans << endl;
    return 0;
}