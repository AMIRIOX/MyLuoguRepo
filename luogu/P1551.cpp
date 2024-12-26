#include <iostream>
#define MAXN 5010
using namespace std;
int fa[MAXN];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int findx(int x) {
    int cur = x;
    while(1) {
        if(cur==fa[cur]) break;
        cur = fa[cur];
    }
    return cur;
}
int join(int john, int lisa) {
    int a1 = findx(john), a2 = findx(lisa);
    if (a1 != a2) fa[a1] = a2;
}
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) fa[i] = i;  // init
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        join(x, y);
    }
    for (int i = 1; i <= p; i++) {
        int a, b;
        cin >> a >> b;
        if (findx(a) == findx(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}