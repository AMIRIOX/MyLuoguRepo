#ifdef DP_METHOD
// O(n^2)
#include <iostream>
using namespace std;
int n, a[100010], f[100010], ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        // f[i]=max(f[i],max f[j]+1 | j<i && a[j]>a[i])
        int maxf = 0;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i])
                maxf = max(maxf, f[j]);
        }
        f[i] = maxf + 1;
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}
#endif

#ifdef BINARY_ANSWER_METHOD
// O(n log n)
#include <iostream>
using namespace std;
int n, a[100010], f[100010];
int t;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        if (t == 0 || a[i] > f[t]) {
            f[++t] = a[i];
            continue;
        }
        int l = 1, r = t;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // 1 2 3 5 | 4
            if (f[mid] < a[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        f[l] = a[i];
    }
    printf("%d\n", t);
    return 0;
}
#endif