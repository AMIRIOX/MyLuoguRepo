#include <algorithm>
#include <cstdio>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e6 + 1;

//* LIS
/*
 * 1 4 8 9 9 6
 */
int d[maxn], a[maxn], n, w;
int ans = -INF;
signed main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = 1;
    }

    //! O(n^2)
    d[1]=1;
    for(int i=2;i<=n;i++) {
        // calc d[i]
        // d[i]=max{ d[j]+1 | j<i, Aj<Ai }

        int maxx=-INF;
        for(int j=1;j<i;j++) {
            if(a[j]<a[i])
                maxx=max(maxx,d[j]);
                //d[i]=max(d[i],d[j]);
        }
        // if(d[i]>maxx) {
        //     cout << i << " " << d[i] << " " << maxx<<endl;
        // }
        d[i]=max(d[i], maxx)+1;
    }
    for(int i=1;i<=n;i++) if(d[i]<=INF) ans=max(ans,d[i]);
    cout << ans << endl;
    cout <<  n-ans << endl;

    //* O(nlogn)
    // d[1] = a[1];
    // int len = 1;
    // for (int i = 2; i <= n; i++) {
    //     if (a[i] >= d[len])
    //         d[++len] = a[i];
    //     else {
    //         int in = upper_bound(d + 1, d + n + 1, a[i]) - d;
    //         d[in] = a[i];
    //     }
    // }
    // cout << len << endl;
    return 0;
}