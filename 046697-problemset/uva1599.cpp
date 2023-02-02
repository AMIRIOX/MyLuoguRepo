// 考虑建图方式
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=400010;
int n, m, d[maxn], vis[maxn];
int color[maxn];
int head[maxn], nxt[maxn], g[maxn];
int tot=1;
void addEdge(int x, int y, int c) {
	g[++tot]=y; color[tot]=c; nxt[tot]=head[x]; head[x]=tot;
}

vector<int> vs;
vector<int> path;

signed main() {
	while(scanf("%d %d", &n, &m)==2) {
		// init
		memset(d, -1, sizeof(d));
		memset(head, 0, sizeof(head));
		// memset(g, 0, sizeof(g));
		// memset(color, 0, sizeof(color));
		// memset(nxt, 0, sizeof(nxt));
		memset(vis, 0, sizeof(vis));
		tot=1;
		path.clear();

		// input
		for(int i=1;i<=m;i++) {
			int x,y,c;
			scanf("%d %d %d", &x, &y, &c);
			addEdge(x, y, c);
			addEdge(y, x, c);
		}

		// first bfs
		queue<int> q; q.push(n); d[n]=0; 
		while(!q.empty()) {
			int cur=q.front(); q.pop();
			for(auto i=head[cur]; i; i=nxt[i]) {
				int fn=g[i];
				if(d[fn]!=-1) continue;
				d[fn]=d[cur]+1;
				q.push(fn);
			}
		}

		// second bfs
		while(!q.empty()) q.pop();
		q.push(1); 
		while(!q.empty()) {
			vs.clear();
			while(!q.empty()) {
				vs.push_back(q.front());
				q.pop();
			}
			// int cur=q.front(); q.pop();  // 不需要这个，我们是考虑多条边
			int minss=0x3f3f3f3f;
			// 题解3在这里直接把q里面的元素转移到v里面 直接用v
			// 因为后面需要两次遍历 第一次查看符合字典序要求的点 第二次拓展节点
			// 如下我不这样做的下场就是，非最小字典序的最短路和最小字典序的最短路
			// 混在一起被push进path中。懂了，寄，先睡觉了。
			// 另外上次bfs已经算出了所有最短路，这次bfs是针对边说话的，注意bdfs的区别
			for(int i=0; i<vs.size(); i++) {
				for(int j=head[vs[i]]; j; j=nxt[j]) {
					int fn=g[j];
					if(d[fn]==d[vs[i]]-1) {
						minss=min(minss,color[j]);
					}
				}
			}
			if(minss != 0x3f3f3f3f) path.push_back(minss);
			// 扩展结点 
			for(int i=0; i<vs.size(); i++) {
				for(int j=head[vs[i]]; j; j=nxt[j]) {
					int fn=g[j];
					if(d[fn]==d[vs[i]]-1 && color[j]==minss && !vis[fn]) {
						q.push(fn);
						vis[fn]=1;			
					}
				}
			}
		}

		//output
		printf("%d\n", path.size());
		for(int i=0; i<path.size(); i++) {
			printf("%d ", path[i]);
		}

	}
	return 0;
}