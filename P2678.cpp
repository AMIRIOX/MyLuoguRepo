#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int L, n, m, a[maxn];
bool check(int x) {
    int current = 0, cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] - a[current] < x)
            cnt++;
        else
            current = i;
        if (cnt > m)
            return false;
    }
    return cnt <= m;
}
int main() {
    scanf("%d %d %d", &L, &n, &m);
    a[0] = 0;
    a[n + 1] = L;
    if (m == 0) {
        printf("%d\n", L);
        return 0;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int l = 1, r = 1e9 + 10, ans;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid;
    }
    printf("%d\n", ans);
    return 0;
}