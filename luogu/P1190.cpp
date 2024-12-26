#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
// 先把范围固定在1~m, 每次找到最小值（多个）同时减去，然后补新的值 循环
int n, w[10020], m, ans;
void minusx(int L, int R, int x) {
    // [L,R]
    for (int i = L; i <= R; i++) {
        w[i] -= x;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    int fish = m ;
    while (fish < n) {
        // cout << fish << endl;;
        sort(w + 1, w + m + 1);
        ans += w[1];
        minusx(1, m, w[1]);
        for (int i = 1; i <= m; i++) {
            if (!w[i]) {
                if (fish + 1 <= n)
                    w[i] = w[++fish];
            } else
                break;
        }
    }
    // cout << "???";
    int maxn = -0x7fffffff;
    for (int i = 1; i <= m; i++) {
        maxn = max(maxn, w[i]);
    }
    printf("%d\n", ans + maxn);
    return 0;
}