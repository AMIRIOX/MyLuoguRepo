#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int n, m;
const int logn = 21;
int logs[maxn + 1], f[maxn][logn + 1];
inline int read() {
    int val = 0, flg = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flg = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = getchar();
    }
    return val * flg;
}

void logo() {
    logs[1] = 0;
    logs[2] = 1;
    for (int i = 3; i <= maxn; i++) {
        logs[i] = logs[i / 2] + 1;
    }
}
int main() {
    // scanf("%d %d", &n, &m);
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
        // scanf("%d", &f[i][0]);
        f[i][0] = read();
    }
    logo();
    /*
    结论：F[x][k] = max F[x,k-1],F[x+2^(k-1),k-1]

    证 关于k-1：
        RMQ a[i][2^j-1] = max Ra(i, i+2^(j-1)-1), Ra(i+2(j-1), i+2^j-1)
        F[i][j] = a[i,i+2^j-1]

        f_2[k-1] of F[x+2^(k-1),k-1] = a_2[x+2^(k-1)+2^(k-1)-1] = a_2[x+2^k-1]
        F[i+2^(j-1),j-1]  = RMQ a[i+2^(j-1), i+2^(j-1)+2^(j-1)-1)]
        = RMQ a(i+2^(j-1), i+2^j-1)
    */
    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int L, R;
        // scanf("%d %d", &L, &R);
        L = read();
        R = read();
        int s = logs[R - L + 1];
        printf("%d\n", max(f[L][s], f[R - (1 << s) + 1][s]));
    }
    return 0;
}