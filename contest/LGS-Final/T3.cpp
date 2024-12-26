#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int n, x, a[maxn], ans = 0x7fffffff, ansl;
int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans = n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j - i + 1 <= ans; j++) {
            if (j > n)
                continue;
            int val = 0;
            for (int k = i; k <= j; k++)
                val = (val | a[k]);
            if (val >= x) {
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    ansl = 1;
                } else if (j - i + 1 == ans)
                    ansl++;
            }
        }
    }
    printf("%d %d\n", ansl, ans);
    return 0;
}