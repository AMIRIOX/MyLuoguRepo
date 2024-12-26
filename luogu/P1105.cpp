#include <cstdio>
#include <iostream>
// #include <utility>
#include <algorithm>
using namespace std;

struct pt {
    int H, L, R, id;
} pts[10020];
pair<int, int> ans[10020];
int n, a, b, c;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        pts[i].H = a;
        pts[i].L = b;
        pts[i].R = c;
        pts[i].id = i;
    }
    sort(pts + 1, pts + 1 + n, [=](const pt i, const pt j) {
        if (i.H != j.H)
            return i.H > j.H;
        else
            return i.id < j.id;
    });
    // for (int i = 1; i <= n; i++) {
    //     printf("%d %d %d %d\n", pts[i].id, pts[i].H, pts[i].L, pts[i].R);
    // }
    for (int i = 1; i <= n; i++) {
        bool ansGotl = false, ansGotr = false;
        for (int j = i + 1; j <= n; j++) {
            if (ansGotl && ansGotr)
                break;
            if (!ansGotl && pts[j].L < pts[i].L && pts[j].R > pts[i].L) {
                ans[pts[i].id].first = pts[j].id;
                ansGotl = true;
            }
            if (!ansGotr && pts[j].L < pts[i].R && pts[j].R > pts[i].R) {
                ans[pts[i].id].second = pts[j].id;
                ansGotr = true;
            }
        }
        if (!ansGotl)
            ans[pts[i].id].first = 0;
        if (!ansGotr)
            ans[pts[i].id].second = 0;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}