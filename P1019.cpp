#include <cstdio>
#include <iostream>
#include <cstring>
const int maxn = 30;
using namespace std;
string words[maxn];
struct edge {
    int to, nxt, v2, self;
    edge() { to = 0, nxt = -1, v2 = 0; }
} g[maxn];
int vis[maxn], n;
int head[maxn], tot, ans, outs;
string strans[40];
void addEdge(int u, int v, int v_) {
    g[++tot].v2 = v_;
    g[tot].to = v;
    g[tot].self = u;
    g[tot].nxt = head[u];
    head[u] = tot;
}
void dfs(int cur, int curans) {
    if (head[cur] == -1) {
        // if (words[cur] == "touch")
        //     printf("%d\n", vis[cur]);
        ans = max(ans, curans);
        return;
    }
    for (int i = head[cur]; ~i; i = g[i].nxt) {
        // printf(".\n");
        // if (words[g[i].self] == "touch" && words[g[i].to] == "choose") {
        //     printf("i hearrrrrr u with %d!\n", vis[g[i].self]);
        // }
        if (vis[g[i].to] < 2) {
            // printf("?\n");
            // if (words[g[i].self] == "at")
            //     cout << "_____fuck you stupid code!!!____" << endl;
            vis[g[i].to]++;

            // cout << "try go " << words[g[i].self] << ">>" << words[g[i].to]
            //      << endl;

            /*
                为什么第二次touch->choose不走了呢？
            */
            // if (words[g[i].to] == "choose")
            //     cout << words[g[i].self] << endl;
            // cout << endl;
            // cout << vis[g[i].to] << endl;
            dfs(g[i].to, curans + g[i].v2);
            vis[g[i].to]--;
        }
    }
    ans = max(ans, curans);
}
void makeEdge(int a, int b) {
    for (int i = (int)words[a].length() - 1; i >= 0; i--) {
        if (words[a][i] == words[b][0]) {
            int pt = 0;
            for (int j = i; j < (int)words[a].length(); j++) {
                if (pt >= (int)words[b].length() || words[a][j] != words[b][pt++])
                    goto BRK;
            }
            if ((words[a] == words[b] && pt != (int)words[a].length()) ||
                (words[a].find(words[b]) == string::npos &&
                 words[b].find(words[a]) == string::npos)) {
                // if(words[a]==words[b] && words[b]==string("tact"))
                // printf("???\n");
                // cout << words[a] << " link to " << words[b]
                //      << ", val= " << words[b].length() - pt << endl;
                addEdge(a, b, (int)words[b].length() - pt);
                return;
            }
        }
    BRK:
        continue;
    }
}
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            // if(words[i]==words[j] && words[i]=="tact") printf("!!!\n");
            makeEdge(i, j);
            if (i != j)
                makeEdge(j, i);
        }
    }
    char dh;
    cin >> dh;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        if (words[i][0] == dh) {
            vis[i]=1;
            dfs(i, (int)words[i].length());
            outs = max(ans, outs);
            ans = 0;
            memset(vis, 0, sizeof(vis));
        }
    cout << outs << endl;

    // for (int i = 1; i <= n; i++) {
    //     for (int u = head[i]; ~u; u = g[u].nxt) {
    //         // printf("%d %d %d\n", g[u].self, g[u].to, g[u].v2);
    //         cout << words[g[u].self] << words[g[u].to] << g[u].v2 << endl;
    //     }
    // }
    return 0;
}
