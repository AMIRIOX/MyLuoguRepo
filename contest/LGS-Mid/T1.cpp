#include <iostream>
#include <cstdio>
const int maxn = 1e5+10;
long long rec[maxn], n, mxa,ans;
signed main() {
    std::cin >> n;
    for(int i=1;i<=n;i++) {
        long long a,b;
        scanf("%lld %lld", &a, &b);
        // mxn=std::max(mxn,a);
        rec[a]+=b;
        if(rec[a]>mxa) {
            mxa=rec[a];
            ans=a;
        }
    }
    printf("%lld\n",ans);
}