#include <cstdio>
#include <iostream>
int a, b, c,d;
int x[120];
int n, up, down;
signed main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    std::cin >> down >> up;
    for (int i = 1; i <= n; i++) {
        if (x[i] > up)
            a += (x[i] - up);
        if (x[i] < down)
            b += (down - x[i]);
        if (x[i] < up)
            c += (up - x[i]);
        if(x[i]>down) d+=(x[i]-down);
    }
    // std::cout << a << " " << b << " " << c << std::endl;
    if(d>=b && a<=c) printf("%d\n",std::max(a,b));
    else printf("-1\n");
    return 0;
}