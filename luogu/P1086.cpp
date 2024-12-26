#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct point {
    int x, y, val;
} a[12200];
bool cmp(point x, point y) {
    return x.val > y.val;
}
int mhd(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x) {
                a[++cnt].x = i;
                a[cnt].y = j;
                a[cnt].val = x;
            }
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    int time = 0, getx = 0, endp = 0;
    if (time + a[1].x + 1 <= k) {
        time = time + a[1].x + 1;
        getx += a[1].val;
    } else {
        printf("0");
        return 0;
    }
    for (int i = 2; i <= cnt; i++) {
        int addx = mhd(a[i], a[i - 1]);
        if (time + addx + 1 <= k) {
            time = time + addx + 1;
            getx += a[i].val;
            endp = i;
        } else
            break;
    }
    for (int j = endp; j >= 1; j--) {
        int endw = a[j].x;
        if (time + endw <= k) {
            time += endw;
            break;
        } else {
            getx -= a[j].val;
            time = time - mhd(a[j], a[j - 1]) - 1;
        }
    }

    printf("%d\n", getx);
    return 0;
}