#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 1e5 + 10;
int a[maxn];

inline int cost(int l, int r) {
    // 计算将 a[l, r] 都变为 a[(l+r)/2] 需要的操作次数
    int p = (l + r) / 2, ap = a[p] - a[p - 1];
    int cost = ap * (p - l) - (a[p - 1] - a[l - 1]);
    cost += (a[r] - a[p + 1 - 1]) - ap * (r - p);
    return cost;
}
signed main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int tot = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        tot += abs(a[i] - a[n / 2]);
        a[i] += a[i - 1];
    }
    if(tot <= k) {
        cout << n << endl;
        return 0;
    }
    int l = 1, r = 1;
    while(l <= r && r <= n) {
        while(r <= n && cost(l, r) <= k) r++;
        ans = max(ans, r - 1 - l + 1);
        if(l == r) { l++; r++; }
        else l++;
    }
    cout << ans << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 10, maxn = 5e5 + 10;

int tot;
struct edge {
    int to, w, nxt;
    edge() { nxt = -1; }
}g[maxm];

void add_edge(int u, int v, int w) {
    tot++;
    g[tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int n, m, s;
priority_queue<node> q;
void dijkstra() {
    
}
signed main() {
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) head[u] = -1;
    return 0;
}
*/
