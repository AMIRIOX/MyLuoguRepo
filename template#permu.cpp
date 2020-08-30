#include <cstdio>
#include <iostream>
#define re register
using namespace std;
const int maxn = 100010;
int n, a[maxn];
void dfs(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        int ok = 1;
        for (int j = 0; j < cur; j++)
            if (i == a[j]) ok = 0;
        if (ok) {
            a[cur] = i;
            dfs(cur + 1);
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
    return 0;
}