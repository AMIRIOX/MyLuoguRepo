#include <cmath>
#include <cstdio>
#include <iostream>
#define Z 1e-4
using namespace std;
double n, m, k;
double check(double mid_) {
    double mon = n;
    for (int i = 0; i < k; i++) {
        mon = mon - m + mon * (mid_ / 100);
    }
    return mon;
}
int main() {
    cin >> n >> m >> k;
    double l = 0, r = 1000, mid;
    while (r - l > Z) {
        mid = l + (r - l) / 2;

        if (check(mid) > Z)
            r = mid;
        else
            l = mid;
    }
    printf("%.1f", l);
}