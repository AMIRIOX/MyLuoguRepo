// for P3379, LCA
#include <iostream>
#include <cstdio>
using namespace std;
int n,m,s,tot,qst;
const int maxn=5e5+10;
int fa[maxn], head[maxn], vis[maxn], ans[maxn*2], qhead[maxn];

template <class T>inline void read(T &x){
	x=0;int ne=0;char c;
	while(!isdigit(c=getchar()))ne=c=='-';
	x=c-48;
	while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+c-48;
	x=ne?-x:x;
	return;
}


// 链式前向星
struct egde{
	int to, w, nxt, self;
}g[maxn*2];
struct quest{
	int y, ok, nxt, rev, num;
}q[maxn*2];

void addEdge(int x, int y, int v){
	g[++tot].to=y;
	g[tot].self=x;
	g[tot].w=v;
	g[tot].nxt=head[x];
	head[x]=tot;
}

// 并查集
int findx(int x) {
	while(x!=fa[x])
		x=fa[x]=fa[fa[x]];
	return x;
}

// tarjan
void tarjan(int u) {
	vis[u]=1;
	for(int i=head[u]; ~i; i=g[i].nxt) {
		if(!vis[g[i].to]) {
			tarjan(g[i].to);
			if(g[i].to!=g[i].self) fa[findx(g[i].to)]=findx(g[i].self);  // 子节点询问处理完之后再和父节点合并
		}
		// vis[g[i].to]=1;         // 子节点处理完毕
	}
	for(int i=qhead[u]; ~i; i=q[i].nxt) {
		// 找到所有和u有询问关系的点
		// for(int i=1;i<=n;i++) {
		// 	cout << vis[i] << " ";
		// }
		if(vis[q[i].y] && !q[i].ok) {
			ans[q[i].num]=findx(q[i].y);
			q[i].ok=q[q[i].rev].ok=1;
		}
	}
}

// 问题
void addQuest(int a, int b, int rk) {
	q[++qst].num=rk;
	q[qst].y=b;
	q[qst].ok=0;
	q[qst].rev=qst+1;
	q[qst].nxt=qhead[a];
	qhead[a]=qst;
	// -------------------- 相同
	q[++qst].num=rk;
	q[qst].y=a;
	q[qst].ok=0;
	q[qst].rev=qst-1;
	q[qst].nxt=qhead[b];
	qhead[b]=qst;
}
signed main() {
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++) {
		fa[i]=i; 
		head[i]=-1;
		qhead[i]=-1;
	}
	for(int i=1; i<=n-1; i++) {
		int x, y;
		// scanf("%d %d", &x, &y);
		read(x),read(y);
		addEdge(x,y,0);
		addEdge(y,x,0);
	}
	for(int i=1;i<=m;i++) {
		int a,b;
		// scanf("%d %d", &a, &b);
		read(a),read(b);
		addQuest(a,b,i);
	}
	tarjan(s);
	for(int i=1;i<=m;i++)  printf("%d\n", ans[i]);
	return 0;
}