#ifdef HEAP_OPT
#include <cstdio>
#include <iostream>
#include <queue>
// #define int long long
// #define INF 9223372036854775800LL
using namespace std;
const int maxn = 5e5 + 10;
struct edge {
    int to, w, nxt;
    edge() { nxt = -1; }
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w) {
    tot++;
    g[tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
struct node {
    int pos, dis;
    node(int pos_, int dis_) : pos(pos_), dis(dis_) {}
    bool operator<(const node& o) const { return this->dis > o.dis; }
};
priority_queue<node> q;
int n, m, s;
int dis[maxn], book[maxn];
void dijkstra() {
    dis[s] = 0;
    q.push(node(s, 0));
    while (!q.empty()) {
        // while (!q.empty() && book[q.top().pos]) q.pop();
        node cur = q.top();
        q.pop();
        int u = cur.pos;
        if (book[u]) continue;
        book[u] = 1;
        for (int i = head[u]; ~i; i = g[i].nxt) {
            if (dis[g[i].to] > dis[u] + g[i].w) {
                dis[g[i].to] = dis[u] + g[i].w;
                if (!book[g[i].to]) {
                    q.push(node(g[i].to, dis[g[i].to]));
                }
            }
        }
    }
}
signed main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i++) head[i] = -1;
    for (int i = 1; i <= n; i++) dis[i] = 0x7fffffff;
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        addEdge(x, y, v);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
    return 0;
}
#endif

#include <iostream>
using namespace std;
const int maxn = 1e4+10;
const int inf = 0x7fffffff;
int G[maxn][maxn], dis[maxn], book[maxn];
int n,m,s;
int minfunc() {
	int minu,minv=inf;
	for(int i=1;i<=n;i++) {
		if(book[i]) continue;
		if(dis[i]<minv) {
			minv = dis[i];
			minu=i;
		}
	}
	return minu;
}
int main() {
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++)
			if(i==j) G[i][j]=0;
			else G[i][j]=inf;
	for(int i=1;i<=m;i++) {
		int x,y,v;
		cin >> x >> y >> v;
		G[x][y] = min(G[x][y],v);
	}
	for(int i=1;i<=n;i++) dis[i] = G[s][i];
	for(int y=1;y<=n-1;y++) {
		int u = minfunc();
		for(int i=1;i<=n;i++) {
			if(G[u][i]!=inf) {
				if(dis[i]>dis[u]+G[u][i]) 
					dis[i]=dis[u]+G[u][i];
			}
		}
		book[u]=1;
	}
	for(int i=1;i<=n;i++) cout << dis[i] << " ";
	return 0;
}

// #include <cstdio>
// #include <iostream>
// #include <queue>
// #define re register
// using namespace std;
// const int maxn = 100;
// const int INF = 0x7fffffff;
// int G[maxn][maxn], n, m, s, dis[maxn], book[maxn];
// // // void dfs(int u) {
// // //     int minx = INF;
// // //     for (int i = 1; i <= n; i++) {
// // //         if (book[i]) continue;
// // //         minx = min(minx, dis[i]);
// // //     }
// // //     for (int i = 1; i <= n; i++) {
// // //         if (G[u][i]) {
// // //             if (dis[i] > dis[u] + G[u][i]) dis[i] = dis[u] + G[u][i];
// // //         }
// // //     }
// // //     book[u] = 1;
// // // }
// // // queue<int> q;
// // // q.push(minfunc());
// // // while (!q.empty()) {
// // //     int i = q.front();
// // //     q.pop();
// // //     for (int j = 1; j <= n; j++) {
// // //         if (G[i][j]) {
// // //             if (dis[j] > dis[i] + G[i][j]) dis[j] = dis[i] + G[i][j];
// // //             q.push(j);
// // //         }
// // //     }
// // //     book[i] = 1;
// // // }

// int minfunc() {
//     int minx = INF, minu;
//     for (int i = 1; i <= n; i++) {
//         if (book[i]) continue;
//         if (dis[i] < minx) {
//             minx = dis[i];
//             minu = i;
//         }
//     }
//     return minu;
// }
// int main() {
//     // input
//     cin >> n >> m >> s;
//     // 注意, 如果有零权的边, 需要将G数组填为INF
//     for (int i = 1; i <= m; i++) {
//         int x, y, v;
//         cin >> x >> y >> v;
//         G[x][y] = v;  //如果有重边 使用min(v, G[x][y]);
//     }
//     //? 设置所有能直接到达1的点的位置的dis[i]为G[1][i]
//     //? 设置不能直接到打1的点的dis[i]为INF, 设置book[1]为1
//     for (int i = 1; i <= n; i++) {
//         if (G[s][i])
//             dis[i] = G[s][i];
//         else
//             dis[i] = INF;
//         if (i == s) dis[i] = 0;
//     }
//     //? 找到一个最小的dis[i], 枚举i点的每条出边(i,j),
//     //? 如果dis[j]>dis[i]+G[i][j],则更新dis[j]=~
//     //? 最后设book[i]为1
//     for (int y = 1; y < n; y++) {
//         // bool isok = 1;
//         // for (int i = 1; i <= n; i++) {
//         //     if (!book[i]) isok = 0;
//         // }
//         // if (isok) break;
//         int i = minfunc();
//         for (int j = 1; j <= n; j++) {
//             if (G[i][j] && i != j) {
//                 if (dis[j] > dis[i] + G[i][j]) dis[j] = dis[i] + G[i][j];
//             }
//         }
//         book[i] = 1;
//     }

//     //? 再次从剩下的边(book[i]==0)找出最小的 然后重复上述操作
//     //? 直到所有边都访问完了
//     for (int i = 1; i <= n; i++) {
//         // cout << "The distance between 1 and " << i << " is " << dis[i] << endl;
//         cout << dis[i] << " ";
//     }
//     return 0;
// }
