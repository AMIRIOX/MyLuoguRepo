// !unaccepted TLE
/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 2e5+10;
int t, n, ok;
long long k;
int a[maxn], vis[maxn];

void dfs(int cur, long long tot, long long mht) {
    if(ok || mht > k || mht+(n-1)*(n-cur+1) < k) return;
    if(cur > n && mht==k) {
        printf("Yes\n");
        for(int i=1; i<=n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        ok=1;
        return;
    }
    for (int i=1; i<=n; i++) {
        if(vis[i]) continue;
        a[cur]=i; vis[i]=1;
        long long nmht = mht + abs(i - cur);
        dfs(cur+1, tot+i, nmht); vis[i]=0;
    }
}

signed main() {
    cin >> t;
    while(t--) {
        ok=0;
        memset(vis, 0, sizeof(vis));
        scanf("%d %lld", &n, &k);
        dfs(1, 0, 0);
        if(!ok) printf("No\n");
    }
    return 0;
}
*/

// correct answer

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5+10;
int t, n;
long long k;
int a[maxn];

signed main() {
    cin >> t;
    while(t--) {
        scanf("%d %lld", &n, &k);
        if(k & 1) { puts("No");  continue;}
        k>>=1;
        for(int i=1; i<=n; i++) a[i]=i;
        for(int i=1; i*2<=n; i++) {
           if(k>=(n-i*2+1)) { swap(a[i], a[n-i+1]); k -= n-i*2+1; } 
           else if(k) { swap(a[i], a[i+k]); k-=k;}
        }
        if(k) { puts("No"); continue;}
        puts("Yes");
        for(int i=1; i<=n; i++) printf("%d%c", a[i], " \n"[i==n]); 
    }
    return 0;
}
