#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int ans;
struct po {
    int a, b;
} a[12200];
bool cmp(po a, po b) {
    return a.a * a.b < b.a * b.b;
}
int main() {
    int n;
    cin >> n;
    cin >> a[0].a >> a[0].b;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].a, &a[i].b);
    }
    sort(a + 1, a + 1 + n, cmp);
    int II = a[0].a;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, II / a[i].b);
        II *= a[i].a;
    }
    printf("%d\n", ans);
    return 0;
}