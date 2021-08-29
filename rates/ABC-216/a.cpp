#include <cstdio>
#include <iostream>
using namespace std;
signed main() {
    int x, y;
    scanf("%d.%d", &x, &y);
    if (y >= 0 && y <= 2) {
        printf("%d-\n", x);
    } else if (y >= 3 && y <= 6) {
        printf("%d\n", x);

    } else if (y >= 7 && y <= 9) {
        printf("%d+\n", x);
    }
    return 0;
}