#include <iostream>
#include <cstdio>
#include <queue>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn = 20;
char field[maxn][maxn];
int dist[200][200][200];
int deg[200], G[200][5];  // 对于i点可扩展的连向节点总数(出度)，邻接表
int s[3], t[3];   // 起点、重点(建图后的标识符)
int movx[]={0, 0, 1, -1, 0};  
int movy[]={0, 1, 0, 0, -1};   // 两点主义：不存在1,1或-1,1-； 对于本题必须要有0，0
int w, h, p;
int debugcnt=0;
int vis[200][200][200];
inline int getID(int a, int b, int c) {
	return (a<<16) | (b<<8) | c;
}
bool conflict(int a1, int b1, int a2, int b2) {
	return ((a2==b2) || (a1==b2 && b1==a2));
}
int tbfs() {
	queue<int> q[2]; // 0 for first, 1 for second
	q[0].push(getID(s[0],s[1],s[2])); q[1].push(t[0], t[1], t[2]);
	dist[s[0]][s[1]][s[2]]=0; dist[t[0]][t[1]][t[2]]=0; 
	vis[s[0]][s[1]][s[2]]=1; vis[t[0]][t[1]][t[2]]=2; 
	int sz[2];
	while(!q[0].empty() && !q[1].empty()) {
		sz[0]=q[0].size(); sz[1]=q[1].size();
		for(int i=0; i<=1; i++) {
			while(sz[i]--) {
				int u=q[i].front(); q[i].pop();
				int ua=(u>>16)&0xff, ub=(u>>8)&0xff, uc=u&0xff;
				for(int i=0; i<deg[ua]; i++) {
					int na=G[ua][i];
					for(int j=0; j<deg[ub]; j++) {
						int nb=G[ub][j];
						if(conflict(ua, ub, na, nb)) continue;
						for(int k=0; k<deg[uc]; k++) {
							int nc=G[uc][k];
							if(conflict(ua, uc, na, nc) || conflict(ub, uc, nb, nc)) continue;
							if(vis[na][nb][nc]==2-i) return dist[na][nb][nc]+dist[ua][ub][uc]+1;
							if(dist[na][nb][nc]==-1) {
								dist[na][nb][nc]=dist[ua][ub][uc]+1;
								vis[na][nb][nc]=i+1;
								q.push(getID(na,nb,nc));
							}
						}
					}
				}
			}
		}
	}
}
signed main() {
	while(~scanf("%d %d %d\n", &w, &h, &p) && p) {
		int id[maxn][maxn], x[200], y[200]; // 唯一标识， 横纵坐标
		int cnt=0;
		memset(vis, 0, sizeof(vis));

		// block 1: 技巧1-for+fgets读入矩阵地图
		for(int i=0; i<h; i++) fgets(field[i], 20, stdin);

		// block 2: 
		/*
			技巧2-x、y数组存第cnt个可操作节点的x、y坐标(空地、鬼或目的地)
			技巧3-为每个可操作节点赋予唯一一个身份标识(递增编号即可)
		*/
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(field[i][j]!='#') {
					x[cnt]=i; y[cnt]=j; id[i][j]=cnt;
					if(isupper(field[i][j])) t[field[i][j]-'A']=cnt;
					else if(islower(field[i][j])) s[field[i][j]-'a']=cnt;
					cnt++;
				}
			}
		}

		// block 3(建图 邻接表):
		for(int i=0; i<cnt; i++) {
			deg[i]=0;
			for(int j=0; j<5; j++) {
				int nx=x[i]+movx[j], ny=y[i]+movy[j];
				if(field[nx][ny]!='#') {
					G[i][deg[i]++] = id[nx][ny];
				}
			}
		}

		if(p <= 2)  { deg[cnt] = 1; G[cnt][0] = cnt;    s[2] = t[2] = cnt++; }
        if(p <= 1)  { deg[cnt] = 1; G[cnt][0] = cnt;    s[1] = t[1] = cnt++; }

        memset(dist, -1, sizeof(dist));

        printf("%d\n", tbfs());
	}
	return 0;
}
