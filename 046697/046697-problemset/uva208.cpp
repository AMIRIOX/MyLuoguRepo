#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=30;
int G[maxn][maxn], vis[maxn];
int path[maxn];
int n, cnt, ansc;
bool bfs() {
	// 判断能否到达
	queue<int> q; q.push(1); vis[1]=1;
	while(!q.empty()) {
		int cur=q.front();  q.pop();
		if(cur==n) return true;
		for(int i=1; i<=maxn; i++) {
			if(i!=cur && G[cur][i] && !vis[i]) {
				q.push(i);
				vis[i]=1;
			}
		}
	}
	return false;
}
void dfs(int cur, int l=2) {
	if(cur==n) {
		for(int i=1; i<l; i++) {
			printf("%d%c", path[i], ((i==l-1)?'\n':' '));
		}
		ansc++;
		return;
	}
	for(int i=1; i<=maxn; i++) {
		if(i!=cur && G[cur][i] && !vis[i]) {
			vis[i]=1;
			path[l]=i;
			dfs(i, l+1);
			vis[i]=0;
			path[l]=0;
		}
	}
}
signed main() {
	while(cin >> n) {
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		memset(path, 0, sizeof(path));
		int x, y; ansc=0;
		while(scanf("%d %d", &x, &y)==2 && x!=0 && y!=0 ){
			G[x][y]=G[y][x]=1;
		}
		if(!bfs()) {
			printf("");
			return 0;
		}
		memset(vis, 0, sizeof(vis));
		printf("CASE %d:\n", ++cnt);
		path[1]=1; vis[1]=1;
		dfs(1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", ansc, n);
	}
	return 0;
}