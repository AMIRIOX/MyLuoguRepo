#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
	先建图并生成 最大生成树
	再对于每个询问q(x,y)，找到x和y的公共祖先
	然后记录这两个点到公共祖先路径中最小的边权
	直接记录x，y在最大生成树上的路径O(n)
	LCA做法O(logn)
*/
int n,m,edn,tot,tut,q;
const int maxn=5e5+10;
const int maxm=1e6+10;
struct edge{
	int x,y,v;
}g[maxm];
struct node{
	int to,w,nxt;
	node() {nxt=-1;}
}gf[maxm];
int fa[maxn], head[maxn], logs[maxn], depth[maxn], fath[maxn][50];
int vis[maxn], dis[maxn][50];
void logo(){
	logs[1]=0;
	logs[2]=1;
	for(int i=3; i<maxn; i++) {
		logs[i]=logs[i/2]+1;
	}
}
int find(int x){
	while(x!=fa[x])
		x=fa[x]=fa[fa[x]];
	return x;
}
void addEdge(int x, int y, int w) {
	gf[++tot].to=y;
	gf[tot].w=w;
	gf[tot].nxt=head[x];
	head[x]=tot;
}
void kruskal() {
	sort(g+1,g+edn+1,[&](const edge& a, const edge& b) {return a.v > b.v; });
	for(int i=1; i<=edn; i++) {
		int uex=find(g[i].x), uey=find(g[i].y);
		if(uex==uey) continue;
		addEdge(g[i].x, g[i].y, g[i].v);
		addEdge(g[i].y, g[i].x, g[i].v);
		fa[uex]=uey;
		if(++tut==n) break;
	}
}
void dfs(int now, int last, int v) {
	vis[now]=1;
	dis[now][0]=v;
	depth[now]=depth[last]+1;
	fath[now][0]=last;
	for(int i=1;i<=logs[depth[now]];i++) {
		fath[now][i]=fath[fath[now][i-1]][i-1];
		dis[now][i]=min(dis[now][i-1], dis[fath[now][i-1]][i-1]);
	}
	
	for(int i=head[now]; ~i; i=gf[i].nxt) {
		if(gf[i].to!=last) dfs(gf[i].to, now, gf[i].w);
	}
}
int lca(int x, int y) {
	if(find(x)!=find(y)) return -1;
	int ans=0x7fffffff;
	// 求路径上最短边权
	if(depth[x] < depth[y]) swap(x, y);
	while(depth[x] > depth[y]) {
		ans=min(ans, dis[x][logs[depth[x]-depth[y]]]);
		x=fath[x][logs[depth[x]-depth[y]]];
	}
	if(x==y) return ans;
	for(int k=logs[depth[x]]; k>=0; k--)
		if(fath[x][k]!=fath[y][k]) {
			ans=min(ans, dis[x][k]);
			ans=min(ans, dis[y][k]);
			x=fath[x][k],y=fath[y][k];
		}
	ans=min(ans, min(dis[x][0], dis[y][0]));
	return ans;
}
int main() {
	logo();
	scanf("%d %d", &n, &m);
	for(int i=1;i<=m;i++) {
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		g[++edn].x=x;
		g[edn].y=y;
		g[edn].v=z;
	}
	scanf("%d", &q);
	for(int i=1;i<=n;i++) {
		fa[i]=i;
		head[i]=-1;
	}
	kruskal();
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i, 0, 0); 

	while(q--) {
		int x,y;
		scanf("%d %d", &x, &y);
		printf("%d\n", lca(x,y));
	}
	return 0;
}