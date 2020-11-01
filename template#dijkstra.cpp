#include <cstdio>
#include <iostream>
#include <queue>
#define re register
using namespace std;
const int maxn = 100;
const int INF = 0x7fffffff;
int G[maxn][maxn], n, m, dis[maxn], book[maxn];
// // void dfs(int u) {
// //     int minx = INF;
// //     for (int i = 1; i <= n; i++) {
// //         if (book[i]) continue;
// //         minx = min(minx, dis[i]);
// //     }
// //     for (int i = 1; i <= n; i++) {
// //         if (G[u][i]) {
// //             if (dis[i] > dis[u] + G[u][i]) dis[i] = dis[u] + G[u][i];
// //         }
// //     }
// //     book[u] = 1;
// // }
// // queue<int> q;
// // q.push(minfunc());
// // while (!q.empty()) {
// //     int i = q.front();
// //     q.pop();
// //     for (int j = 1; j <= n; j++) {
// //         if (G[i][j]) {
// //             if (dis[j] > dis[i] + G[i][j]) dis[j] = dis[i] + G[i][j];
// //             q.push(j);
// //         }
// //     }
// //     book[i] = 1;
// // }

int minfunc() {
    int minx = INF, minu;
    for (int i = 1; i <= n; i++) {
        if (book[i]) continue;
        if (dis[i] < minx) {
            minx = dis[i];
            minu = i;
        }
    }
    return minu;
}
int main() {
    // input
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        G[x][y] = v;
    }
    //? 设置所有能直接到达1的点的位置的dis[i]为G[1][i]
    //? 设置不能直接到打1的点的dis[i]为INF, 设置book[1]为1
    for (int i = 1; i <= n; i++) {
        if (i == 1) dis[i] = 0;
        if (G[1][i])
            dis[i] = G[1][i];
        else
            dis[i] = INF;
    }
    dis[1] = 0;
    //? 找到一个最小的dis[i], 枚举i点的每条出边(i,j),
    //? 如果dis[j]>dis[i]+G[i][j],则更新dis[j]=~
    //? 最后设book[i]为1
    for (int y = 1; y < n; y++) {
        // bool isok = 1;
        // for (int i = 1; i <= n; i++) {
        //     if (!book[i]) isok = 0;
        // }
        // if (isok) break;
        cout << "截至到这里, 一切正常!" << endl;
        int i = minfunc();
        for (int j = 1; j <= n; j++) {
            if (G[i][j] && i != j) {
                if (dis[j] > dis[i] + G[i][j]) dis[j] = dis[i] + G[i][j];
            }
        }
        book[i] = 1;
    }

    //? 再次从剩下的边(book[i]==0)找出最小的 然后重复上述操作
    //? 直到所有边都访问完了
    for (int i = 1; i <= n; i++) {
        cout << "The distance between 1 and " << i << " is " << dis[i] << endl;
    }
    return 0;
}