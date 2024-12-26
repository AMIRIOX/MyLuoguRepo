#include <iostream>
#include <cstring>
#define maxn 100010
using namespace std;
struct node {
    int left, right, father, value;
} t[maxn];
int vis[maxn],ans=0x7fffffff;
int dfs(int x, int d) {
    if (!x || vis[x]) return 0;
    vis[x] = 1;
    return dfs(t[x].left, d + 1) + dfs(t[x].right, d + 1) +
           dfs(t[x].father, d + 1) + t[x].value * d;
}
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i].value >> t[i].left >> t[i].right;
    }
    for(int i=1;i<=n;i++) {
        t[t[i].left].father=i;
        t[t[i].right].father=i;
    }
    for(int i=1;i<=n;i++) {
        memset(vis,0,sizeof vis);
        ans=min(ans,dfs(i,0));
    }
    cout << ans;
    return 0;
}