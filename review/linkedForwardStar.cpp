#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 8e6+10;
struct edge{
	int to,w,nxt;
	edge() { nxt = -1; }
}g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w) {
	tot++;
	g[tot].to = to;
	g[tot].w = w;
	g[tot].nxt = head[u];
	head[u] = tot;
}
int main() {
	int n,m,flg;
	scanf("%d %d %d", &n, &m, &flg);
	for(int i=0;i<=n;i++) head[i]=-1;	
	for(int i=1;i<=m;i++) {
		int x,y,v;
		scanf("%d %d %d", &x, &y, &v);
		if(flg) {
			addEdge(x,y,v);
		}else {
			addEdge(x,y,v);
			addEdge(y,x,v);
		}
	}
	for(int u=1;u<=n;u++) {
		for(int i=head[u]; ~i; i=g[i].nxt) {
			printf("%d %d %d\n", u, g[i].to, g[i].w);
		}
	}
	return 0;
}