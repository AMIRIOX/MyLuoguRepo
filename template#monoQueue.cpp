#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], q[maxn], n, k;
void getmin() {
    int head = 0, tail = 0;
    for (int i = 1; i < k; i++) {
        while (head <= tail && a[q[tail]] >= a[i])
            tail--;
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head <= tail && a[q[tail]] >= a[i])
            tail--;
        q[++tail] = i;
        while (q[head] <= i - k)
            head++;
        printf("%d ", a[q[head]]);
    }
}
void getmax() {
    int head = 0, tail = 0;
    for (int i = 1; i < k; i++) {
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
        while (q[head] <= i - k)
            head++;
        printf("%d ", a[q[head]]);
    }
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    getmin();
    printf("\n");
    getmax();
    printf("\n");
    return 0;
}