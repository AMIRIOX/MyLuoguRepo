// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #define debug { cout << "bug occured" << endl; }
// using namespace std;
// const int maxn = 20;
// int G[maxn][maxn];
// int vis[maxn]; int n, ans, tot, ans2;
// int dfs(int cur) {
// 	vis[cur]=ans;
// 	int dfsed=0;
// 	for(int i=1; i<=n; i++) {
// 		if(!vis[i] && i!=cur && G[cur][i]) { dfsed+=dfs(i); dfsed++; }
// 	}
// 	return dfsed?dfsed-1:0;
// }
// signed main(){
// 	while(cin >> n && n!=0) {
// 		memset(G, 0, sizeof(G));
// 		memset(vis, 0, sizeof(vis));
// 		int x,y; ans=1;
// 		while(scanf("%d %d", &x, &y)==2 &&x!=-1 && y!=-1)
// 			G[x][y]=G[y][x]=1;
// 		vis[1]=ans; ans2+=dfs(1);
// 		for(int i=1; i<=n; i++) {
// 			if(!vis[i]) { ++ans; ans2+=dfs(i); }
// 		}
// 		printf("Set %d: Minimum links to open is %d\n", ++tot, ans-1+ans2);
// 	}
// 	return 0;
// }