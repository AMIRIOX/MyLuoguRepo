#include <iostream>
#include <cstdio>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e5+10;

signed main() {
    int x,y;
    cin >> x >> y;
    int ans = ((x>>y)&1);
    cout << ans;
    return 0;
}