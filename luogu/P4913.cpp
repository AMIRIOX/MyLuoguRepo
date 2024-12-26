#include <iostream>
#define MAXN 1000010
using namespace std;
int n = 0;
struct node {
    int left, right;
} t[MAXN];
void build() {
    for (int i = 1; i <= n; i++) 
        scanf("%d %d", &t[i].left, &t[i].right);
}
int dfs(int x) {
    if (!x) return 0;
    return max(dfs(t[x].left), dfs(t[x].right)) + 1;
}
int main() {
    cin >> n;
    build();
    cout << dfs(1);
    return 0;
}