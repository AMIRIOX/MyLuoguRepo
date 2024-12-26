#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 610;
int bucket[maxn];
int main() {
    int n, x, w;
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        bucket[x]++;
        int sum = 0;
        for (int f = 600; f >= 0; f--) {
            sum += bucket[f];
            if (sum >= max(1, i * w / 100)) {
                printf("%d ", f);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
