#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e8 + 10;
int a[MAXN], b[MAXN];
inline int read() {
    int val = 0, flg = 1;
    char ch = (char)getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') flg = 0;
        ch = (char)getchar();
    }
    while (ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char)getchar();
    }
    return (flg ? val : (~val) + 1);
}
int main() {
    int n, q, cnt = 0;
    n = read();
    q = read();
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            b[cnt++] = i;
            for (int j = i << 1; j <= n; j += i) {
                a[j] = 1;
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int x = read();
        // for (int i = 0; i <= n; i++) {
        //     if (a[i] == 0) x--;
        //     if (x == 0) {
        //         cout << i << endl;
        //         break;
        //     }
        // }
        cout << b[x-1] << endl;
    }
    // for(int i=0;i<n;i++) {
    //     cout << b[i] << ' ';
    // }
    return 0;
}