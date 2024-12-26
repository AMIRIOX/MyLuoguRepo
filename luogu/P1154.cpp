#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1000010;
int s[maxn];
int tag[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            tag[abs(s[i] - s[j])] = 1;
        }
    }
    // a与b在模m意义下同余（余数相同）时 存在 m|(a-b)
    // 那么只需要找到最小的不能整除a-b的
    // 思路是从1开始枚举i，如果i的所有 小于最大值的 倍数都没被标记即可
    for (int i = 1; i <= maxn; i++) {
        bool ok = true;
        for (int j = i; j <= maxn; j += i) {
            if (tag[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("NO ANSWER\n");
    return 0;
}