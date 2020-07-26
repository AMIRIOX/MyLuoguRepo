#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
int a[1000001];
int ans;
signed main() {
    signed n, C;
    cin >> n >> C;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0; i<n; i++) {
        ans+=upper_bound(a,a+n,a[i]+C)-lower_bound(a,a+n,a[i]+C);
    }
    cout << ans;
}