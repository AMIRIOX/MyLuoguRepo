#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
const int maxn = 3e6 + 10;
stack<int> s;
int n, a[maxn], ans[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        ans[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
