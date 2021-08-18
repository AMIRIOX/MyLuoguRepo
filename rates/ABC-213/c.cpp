// #include <cstdio>
// #include <iostream>
// #include <map>
// using namespace std;
// const int maxhw = 1e9 + 10;
// const int maxn = 1e5 + 10;
// int bookr[maxn], bookc[maxn], h, w, n;
// map<string, bool> bookr_, bookc_;
// struct card {
//     int x, y;
// } a[maxn];
// signed main() {
//     scanf("%d %d %d", &h, &w, &n);
//     for (int i = 1; i <= n; i++) {
//         scanf("%d %d", &a[i].x, &a[i].y);
//         // bookr[a[i].x] = bookc[a[i].y] = 1;
//         bookr_[to_string(a[i].x)]=true;
//         bookc_[to_string(a[i].y)]=true;
//     }
//     int mov = 0;
//     for (int i = 1; i <= h; i++) {
//         if (!bookr_[to_string(i)]) {
//             mov++;
//         } else {
//             for (int j = 1; j <= n; j++) {
//                 if (a[j].x == i) {
//                     a[j].x -= mov;
//                 }
//             }
//         }
//     }
//     mov = 0;
//     for (int i = 1; i <= w; i++) {
//         if (!bookc_[to_string(i)]) {
//             mov++;
//         } else {
//             for (int j = 1; j <= n; j++) {
//                 if (a[j].y == i)
//                     a[j].y -= mov;
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         printf("%d %d\n", a[i].x, a[i].y);
//     }
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxhw = 1e9 + 10;
const int maxn = 1e5 + 10;
struct card {
    int x, y, id;
} a[maxn];
int h, w, n;
signed main() {
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    int last, cnt = 0;
    sort(a + 1, a + n + 1, [=](card i, card j) { return i.x < j.x; });
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].x != last)
            cnt++;
        last = a[i].x;
        a[i].x = cnt;
    }

    cnt = 0;
    sort(a + 1, a + n + 1, [=](card i, card j) { return i.y < j.y; });
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].y != last)
            cnt++;
        last = a[i].y;
        a[i].y = cnt;
    }

    sort(a + 1, a + n + 1, [=](card i, card j) { return i.id < j.id; });
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", a[i].x, a[i].y);

    return 0;
}