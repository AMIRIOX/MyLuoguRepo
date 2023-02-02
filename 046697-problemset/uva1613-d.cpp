#include <iostream>
#include <cstdio>
using namespace std;
int n, m; const int maxn=1e4+10;
int G[maxn][maxn], color[maxn], in[maxn];
signed main() {
	while(cin >> n >> m) {
		int ai,bi; int ans=0;
		memset(G, 0, sizeof(G)); memset(color, 0, sizeof(color));
		for (int i=1; i<=m; i++) {
			scanf("%d %d", &ai, &bi);
			G[ai][bi]=G[bi][ai]=1;
			in[ai]++, in[bi]++;
			ans=max(ans, max(in[ai], in[bi]));
		}
		color[1]=1;
		for(int i=2; i<=n; i++) {
			int ki=1;
			for(int j=1; j<=n; j++) {
				if(G[i][j]) {
					if(color[j]==ki) ki++;
				}  
			}
			ans=max(ans, ki);
			color[i]=ki; 
			// cout << "color[" << i << "]=" << ki << endl;
		}
		cout << (ans%2?ans:ans+1) << endl;
		for(int i=1; i<=n; i++) cout << color[i] << endl;
		cout << endl;
	}
	return 0;
}