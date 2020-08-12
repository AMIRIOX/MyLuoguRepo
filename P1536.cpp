#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 50100
using namespace std;
int fa[MAXN],t[MAXN];
//TODO: 不使用桶排  用
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void join(int john, int lisa) {
    int a1 = find(john), a2 = find(lisa);
    if (a1 != a2) fa[a1] = a2;
}
int statistics() {}
int main() {
    int n,m;
    cin >> n;
    if(n!=0) cin>>m;
    while (n!=0) {
        memset(fa, 0, sizeof fa);
        memset(t,0,sizeof t);
        int ans = 0;


        for(int i=1;i<=n;i++) {
            fa[i]=i;
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            join(x, y);
        }
        for (int i = 1; i <= n; i++) {
            // if (fa[i] = i) ans++;
            t[find(i)]=1;
        }
        for (int i = 1; i <= n; i++) {
            if(t[i]) ans++;
        }
        cout << (ans - 1) << endl;


        cin >> n;
        if(n!=0) cin >> m;
    }
    return 0;
}