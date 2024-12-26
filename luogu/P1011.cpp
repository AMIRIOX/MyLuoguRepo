#include <cstdio>
#include <iostream>
using namespace std;
int suma[12000], sumb[12000];
signed main() {
    int a, n, m, x;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    /*suma[1] = */ suma[2] = 1;
    sumb[1] = sumb[2] = 0;
    suma[3] = 2, sumb[3] = 0;
    for (int i = 4; i <= n; i++) {
        suma[i] = suma[i - 1] + suma[i - 2] - 1;
        sumb[i] = sumb[i - 1] + sumb[i - 2] + 1;
    }
    int b = m - suma[n-1] * a;
    b /= sumb[n-1];
    cout << suma[x]*a+sumb[x]*b << endl;
    return 0;
}