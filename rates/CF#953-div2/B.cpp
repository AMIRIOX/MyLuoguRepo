#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t;
long long n, a, b, ans;
signed main() {
    cin >> t;
    while(t--) {
        scanf("%lld %lld %lld", &n ,&a, &b);
        if(b<=a) ans=n*a;
        else {
            long long k = min(b-a+1, n);
            ans = (n-k)*a;
            ans += k*(b-k+1)+k*(k-1)/2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
