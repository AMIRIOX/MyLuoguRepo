#include <cstdio>
using namespace std;
// #define int long long
int n, k, a[2020], tot;
int tmp[2020];
bool isprime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
void dfs(int lv, int sum, int gsum) {
    if(lv == n + 1) {
        if(isprime(sum) && gsum == k) tot++;
        // for(int i=1;i<=n;i++) {
        // if(tmp[i]) printf("%d ", a[i]);
        // if(tmp[i] && i!=n) printf("+ ");
        // }printf("= %d\n", sum);
    } else {
        // tmp[lv]=1;
        dfs(lv + 1, sum + a[lv], gsum + 1);
        // tmp[lv]=0;
        dfs(lv + 1, sum, gsum);
    }
}
signed main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    dfs(1, 0, 0);
    printf("%d\n", tot);
    return 0;
}