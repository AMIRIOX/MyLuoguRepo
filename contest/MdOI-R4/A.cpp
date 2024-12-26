#include <cstdio>
#include <iostream>
using namespace std;
int ans, dls;
int n, m, types;
int ti[120], qi[120];
int main() {
    scanf("%d %d %d", &n, &m, &types);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ti[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &qi[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (qi[i] && ti[i])
            dls++;
        else
            ans++;
    }
    if (dls >= m)
        printf("%d\n", ans + m);
    else
        printf("%d\n", n);
    return 0;
}