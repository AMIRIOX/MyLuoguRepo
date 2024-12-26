#include <cstdio>
#include <iostream>
using namespace std;
int n, a[12000], b[12000];
double s, sum;
int p;
int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        s += (double)(a[i] * b[i] / sum);
    }
    printf("%.2f\n", s * 0.8 + p * 0.2);
    return 0;
}
