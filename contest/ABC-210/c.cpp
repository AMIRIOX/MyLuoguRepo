#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 3e5 + 10;
// const int mod = 38833;
int a[maxn], ans = 0;
// int has[mod + 10];
// long long qzh[maxn];
signed main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        // qzh[i]=qzh[i-1]+a[i];
    }
    int curans = 0;
    map<long long, int> m;
    for (int i = 1; i <= n - k + 1; i++) {
        // memset(has, 0, sizeof(has));
        if (i == 1) {
            for (int j = 1; j <= k; j++) {
                if (!m.count(a[j])) {
                    ans++;
                }
                m[a[j]]++;
            }
        } else {
            m[a[i - 1]]--;
            if (!m[a[i - 1]])
                m.erase(a[i - 1]);
            m[a[i + k - 1]]++;
            if (m.size() > ans)
                ans = m.size();
        }
    }
    printf("%d\n", ans);
    return 0;
}