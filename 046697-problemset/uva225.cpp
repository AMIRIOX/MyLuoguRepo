#include <iostream>
#include <cstdio>
#include <cstring>
#define debug {cout << "fuck--" << endl;}
using namespace std;
const int maxn = 300;
int G[maxn][maxn], vis[maxn][maxn], op[maxn];
int sjhshks, n, k, ansc;
const char operations[4]={'e','n','s','w'};
const int movx[4]={1, 0, 0, -1};
const int movy[4]={0, 1, -1, 0};
bool moveok(int x, int y, int i, int l) {
	for(int c=1; c<=l; c++) {
		x+=movx[i]; y+=movy[i];
		if(x<0 && x>n+120 && y<0 && y>n+120) return false;
		if(G[x+120][y+120]==-1) return false;
		if((c==1 || c==l) && vis[x+120][y+120]) return false;
	}
	return true;
}
void dfs(int x, int y, int l, int last=-1) {
	if(x==0 && y==0 && l>n) {
		// solution founded
		ansc++;
		for(int i=1; i<l; i++) {
			printf("%c", operations[op[i]]);
			if(i==l-1) puts("");
		}
		return;
	}else if(l>n) {
		return;
	}
	for(int i=0; i<4; i++) {
		if(i==last || i+last==3) continue;
		int nx=x+movx[i]*l, ny=y+movy[i]*l;
		if(/*G[nx+120][ny+120]!=-1*/moveok(x, y, i, l) && !vis[nx+120][ny+120]) {
			// 这里有一个问题是 不仅仅是拐点不能过障碍，中间路线也不能。(moveok)
			vis[nx+120][ny+120]=1;
			op[l]=i;
			dfs(nx, ny, l+1, i);
			vis[nx+120][ny+120]=0;
		}
	}
}
signed main() {
	cin >> sjhshks;
	while(sjhshks--) {
		memset(G, 0,  sizeof(G));
		memset(vis, 0, sizeof(vis));
		ansc=0;
		scanf("%d %d", &n, &k);
		int x=0, y=0;
		for(int i=1; i<=k; i++) {
			scanf("%d %d", &x, &y);
			G[x+120][y+120]=-1;
		}
		dfs(0,0,1);
		printf("Found %d golygon(s).\n", ansc);
	}
	return 0;
}