#include <cstdio>
#include <iostream>
// #include <stack>
using namespace std;
const int maxn = 1e7 + 10;
// int n2[maxn];

int main() {
    int n;
    scanf("%d", &n);
    if ((n & 1) || n < 2) {
        printf("-1\n");
        return 0;
    }
    // n2[0] = 1;
    // n2[1] = 2;
    // for (int i = 2; i < maxn; i++) {
    //     n2[i] = n2[i - 1] * 2;
    // }
    while (n > 0) {
        int num = 1;
        while (num * 2 <= n) {
            num *= 2;
        }
        printf("%d ", num);
        n -= num;
    }
    printf("\n");
    return 0;
}