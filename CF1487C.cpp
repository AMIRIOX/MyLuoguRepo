#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 2e4 + 10;

int n, a[maxn];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        // 全队总得分 3a+2b = 3(a+b)-b
        // 比赛总场数 a+b=n(n-1)/2
        // 3(n(n-1)/2)+b 总分
        // b最小 3(n(n-1)/2)%n
        // 个人总分 3(n(n-1)/2)/n | b严格小于n
        int tot = n * (n - 1) / 2;
        int b = 3 * tot % n;
        int pts = (3 * tot - b) / n;
        for (int i = 1; i <= n; i++) {
            int cur = i + 1;
            int q = pts - a[i];
            while (q >= 3) {
                q -= 3;
                ++cur;
                a[i] += 3;
                printf("1 ");
            }
            while (q) {
                q--;
                a[i]++;
                a[cur++]++;
                printf("0 ");
            }
            while (cur <= n) {
                a[cur++] += 3;
                printf("-1 ");
            }
        }
        puts("");
    }
}