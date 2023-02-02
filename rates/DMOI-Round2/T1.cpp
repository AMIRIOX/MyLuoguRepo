#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define debug {cout << "fuck debug" << endl;}
using namespace std;
const int maxn=1e3+10;
const int maxn2=2e5+10;
int n, m, S, B, F;
int G[maxn][maxn], P[maxn][maxn];
int links[maxn2];
signed main() {
	cin >> n >> m >> S >> B >> F;
	if(n<=800 && m<=2000) {
		memset(G,0x3f3f3f3f,sizeof(G));
		for(int i=1; i<=m; i++) {
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			G[u][v]=G[v][u]=w;
		}
		for(int i=1; i<=n; i++) {
			G[i][i]=0;
			for(int j=1; j<=n; j++) {
				P[i][j]=j;
			}
		}
		for(int k=1; k<=n; k++)for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)
			if(G[i][j]>G[i][k]+G[k][j]) {
				G[i][j]=G[i][k]+G[k][j];
				P[i][j]=P[i][k];
			}else if(G[i][j]==G[i][k]+G[k][j]) {
				if(P[i][j]>P[i][k] && i!=k) {
					P[i][j]=P[i][k];
				}
			}

	// 枚举S到F的最短路上的点ki，求ki到F的最短路
		int k=P[S][F];
		do{
			// k
			if(G[B][k]*2<=G[S][k]*3) {
		//no
				printf("NO\n");
				double ans= max(double(G[B][k])/3.0, double(G[S][k])/2.0);
				if(floor(ans)==ans) cout << floor(ans) << endl;
				else cout << ans << endl;
				return 0;
			}
			k=P[k][F];
		}while(k!=F && k!=0);

		//yes
		printf("YES\n");
		int k2=P[B][F], last=B, al=0;
		while(k2!=F && k2!=0) {
			// k2
			if(G[B][k2]*2 > G[S][F]*3) {
				double ans= double(G[F][last])-double(G[S][F])/2.0*3.0;
				if(floor(ans)==ans) cout << floor(ans) << endl;
				else cout << ans << endl;
				return 0;
			}
			last=k2;
		}
	}else {

	}

	return 0;
}