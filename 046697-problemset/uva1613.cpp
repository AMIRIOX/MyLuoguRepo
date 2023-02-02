#include <iostream>
#include <cstdio>
#define subPoint for(int i=1; i<=n; i++) if(G[cur][i]) 
using namespace std;
int n, m, ans; const int maxn=1e4+10;
int G[maxn][maxn], color[maxn], in[maxn], bookColor[maxn];
void dfs(int cur) {
	// 贪心要求子问题的最优解能合并成总问题的最优解
	// 对于图论贪心问题而言，绝大多数要求子问题合并成总问题的都要和连边有关
	memset(bookColor, 0, sizeof(bookColor));
	subPoint bookColor[color[i]]=1;
	for(int i=1; i<=ans; i++) if(!bookColor[i]) { color[cur]=i; break; }
	subPoint if(!color[i]) dfs(i);
	// subPoint if(!color[i]) {cout << "now is " << cur << ", and next is subpoint: " << i << endl; dfs(i);}
}
signed main() {
	while(cin >> n >> m) {
		int ai,bi; ans=0;
		memset(G, 0, sizeof(G)); memset(color, 0, sizeof(color));
		memset(in, 0, sizeof(in));
		for (int i=1; i<=m; i++) {
			scanf("%d %d", &ai, &bi);
			G[ai][bi]=G[bi][ai]=1;
			in[ai]++, in[bi]++;
			ans=max(ans, max(in[ai], in[bi]));
		}
		dfs(1);
		cout << (ans&1?ans:ans+1) << endl;
		for(int i=1; i<=n; i++) cout << color[i] << endl;
		puts("");
	}
	return 0;
}
