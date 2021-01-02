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