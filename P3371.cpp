#include <iostream>
using namespace std;
const int maxn = 8e6+10;
const int inf = 0x7fffffff;
int dis[maxn], book[maxn];
int head[maxn], tot;
struct edge{
	int to,w,nxt;
	edge() { nxt = -1; }
}g[maxn];
void addEdge(int u, int to, int w) {
	tot++;
	g[tot].to = to;
	g[tot].w = w;
	g[tot].nxt = head[u];
	head[u] = tot;
}
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
	for(int i=0;i<=n;i++) head[i]=-1;
	for(int i=1;i<=m;i++) {
		int x,y,v;
		cin >> x >> y >> v;
		addEdge(x, y, v);
	}
	for(int i=1;i<=n;i++) dis[i] = inf;
	dis[s]=0;
	for(int y=1;y<=n-1;y++) {
		int u = minfunc();
		for(int i=head[u]; ~i; i=g[i].nxt) {
			if(dis[g[i].to]>dis[u]+g[i].w){
				dis[g[i].to]=dis[u]+g[i].w;
			}
		}
		book[u]=1;
	}
	for(int i=1;i<=n;i++) cout << dis[i] << " ";
	return 0;
}