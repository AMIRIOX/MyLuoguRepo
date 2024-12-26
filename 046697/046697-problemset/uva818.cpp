#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50;
int G[maxn][maxn], vis[maxn];
int n, num, data, ans;
bool haveTwo(int s) {
	for(int i=1; i<=n; i++) {
		int cnt=0;
		for(int j=1; j<=n; j++) {
			if(G[i][j] && !(s&(1<<j)) && !(s&(1<<i))) {
				cnt++;
				if(cnt>2) return true;
			}
		}
	}
	return false;
}
bool dfs(int cur, int fa, int s) {
	vis[cur]=1;
	for(int i=1; i<=n; i++) {
		if(G[cur][i] && i!=fa && !(s&(1<<i))) {
			if(vis[i]) return true;
			if(dfs(i, cur, s)) return true;
		}
	}
	return false;
}
bool haveCircle(int s) {
	memset(vis, 0, sizeof(vis));
	for(int i=1; i<=n; i++) {
		if(!vis[i] && !(s&(1<<i))) {
			num++;
			if(dfs(i, -1, s)) return true;
		}
	}
	return false;
}
void solve() {
	ans=0x7fffffff;
	for(int s=0; s<(1<<n); s++) {
		num=0;
		if(haveCircle(s) || haveTwo(s)) continue;
		int count=0;
		for(int i=1; i<=n; i++) {
			if(s&(1<<i)) count++;
		}
		if(num<=count+1) {
			// printf("Set %d: Minimum links to open is %d\n", ++data, count);
			ans=min(ans, count);
		}
	}
}
// 1. 二进制枚举状态(n<=15想)，1代表环解开
// 2. 状态合法性：(1)无环; (2)每个点度数最多为2; (3)连通分量<=解开环数+1(每个解开的环最多只能连接两个连通分量)
signed main() {
	while(cin >> n && n!=0) {
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		int x,y;  num=0;
		while(scanf("%d %d", &x, &y)==2 &&x!=-1 && y!=-1)
			G[x][y]=G[y][x]=1;
		solve();
		printf("Set %d: Minimum links to open is %d\n", ++data, ans);
	}
	return 0;
}