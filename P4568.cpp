#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

// 思路1 分层图（拆点的思想）

// 思路2 dijkstra+dp.
// 分析复杂度，发现floyd的O(n^3)不满足条件
// 所以考虑dijkstra。但是发现一维的dijkstra无法转移二维的问题
// （另一维是用了多少次机会）所以考虑dp


const int N = 1e4 + 10;
const int K = 11;
const int INF = 0x3f3f3f3f;
int n, m, k, s, t;
int G[N][N];
int dis[N][K];
struct node {
    int pos, val;
    node(int _pos, int _val) : pos(_pos), val(_val) {}
    bool operator<(const node& o) const { return this->val > o.val; }
};
priority_queue<node> q;
void dijk() {
    // 初始化每个点枚举所有次数的最短路都是无穷大
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++)
            dis[i][j] = INF;
    }

    // 起点使用任意次数的免费券最短路都是0
    for (int i = 0; i <= k; i++)
        dis[s][i] = 0;

    // 枚举dp中k的取值
    for (int i = 0; i <= k; i++) {
        // 加入起点
        q.push(node(s, 0));
        while (!q.empty()) {
            node x = q.top();
            q.pop();
            // 如果x的最短路已经大于x已记录的最短路说明松驰过
            if (x.val > dis[x.pos][i])
                continue;

            // 枚举x点连的边
            for (int y = 0; y < n; y++) {
                if (G[x.pos][y] != INF) {  // 如果x->y的边存在
                    bool updated = false;
                    if (dis[y][i] > dis[x.pos][i] + G[x.pos][y]) {
                        // 如果不使用免费券，正常dijkstra
                        dis[y][i] = dis[x.pos][i] + G[x.pos][y];
                        // printf("@%d\n", dis[y][i]);

                        updated = true;
                    }
                    if (i)
                        if (dis[y][i] > dis[x.pos][i - 1]) {
                            // 如果使用免费券，到达这个点就不花钱，即最短路为x的最短路
                            dis[y][i] = dis[x.pos][i - 1];
                            // printf("*%d\n", dis[y][i]);

                            updated = true;
                        }
                    if (updated)
                        q.push(node(y, dis[y][i]));
                }
            }
        }
    }
}
int main() {
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G[i][j] = INF;
    for (int i = 0; i < n; i++)
        G[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a][b] = G[b][a] = min(G[a][b], c);
    }
    dijk();

    printf("%d\n", dis[t][k]);

    return 0;
}
