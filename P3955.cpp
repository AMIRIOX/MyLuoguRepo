#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int book[1010], reader[1010][2];
bool check(int bk, int need, int bt) {
    int mod = pow(10, bt);
    return bk%mod == need;
}
signed main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &book[i]);
    sort(book + 1, book + n + 1);
    for (int i = 1; i <= q; i++)
        scanf("%d %d", &reader[i][0], &reader[i][1]);
    for(int i=1; i<=q ;i++) {
            bool flag=false;
        for(int j=1;j<=n;j++) {
            if(flag=check(book[j],reader[i][1], reader[i][0])) {
                printf("%d\n", book[j]);
                break;
            }
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}