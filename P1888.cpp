#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a[3];
int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}
int main() {
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    int mg = gcd(a[0], a[2]);
    printf("%d/%d\n", a[0] / mg, a[2] / mg);
    return 0;
}