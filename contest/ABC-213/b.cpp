#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 10;
int n;
struct player {
    int val;
    int id;
} a[maxn];
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].val);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, [=](player x, player y) { return x.val > y.val; });
    printf("%d\n", a[2].id);
    return 0;
}