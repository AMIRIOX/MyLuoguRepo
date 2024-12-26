// TODO: bad code
// 直接一行一行或一列一列转移，在每个点周围四格枚举记录答案
// 也就是转移和计算答案分开，或者说答案的计算并不和转移绑定
// 由于dfs的解答树完整，加上vis=1——dfs——vis=0的连贯特性
// 并不用担心会出现搜索不到的状态。
// 而转移和计算答案绑定会导致有些地方走死路口，因此这种只适用于寻找路径类的问题

/*
牧之原偏微分算子 20:24:31
他的转移和标记答案是分开的

牧之原偏微分算子 20:24:36
我思维定势了
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define debug { cout << "debug" << endl; }
#define debug2 {  }
using namespace std;
int matrix[10][10], ans[10][10];
int movx[]={0, 1, -1, 0};
int movy[]={1, 0, 0, -1};
int domino[10][10], vis[10][10], vis2[10][10];
int data=0, ansc=0, tmpflag=0;
bool read() {
	if(scanf("%d", &matrix[1][1])==1) {
		for(int i=1;i<=7; i++) {
			for(int j=1; j<=8; j++) {
				if(i==1 && j==1) continue;
				scanf("%d", &matrix[i][j]);
			}
		}	
		return true;
	}
	return false;
}
void outputans() {
	for(int i=1; i<=7; i++) {
		for(int j=1; j<=8; j++) {
			printf("%d%c", ans[i][j], ((j==8)?'\n':' '));
		}
	}	
}
inline bool check(int x, int y) {
	return x>=1 && x<=7 && y>=1 && y<=8 && !vis2[x][y];
}
void dfs(int x, int y, int last, int lx, int ly) {
	if(tmpflag==28) {
		tmpflag=0;
		int amx=min(last, matrix[x][y]), bmx=max(last, matrix[x][y]);
		if(!vis[amx][bmx]) {
			ansc++;
			ans[x][y]=ans[lx][ly]=domino[amx][bmx];
			outputans(); 
		}
	}
	if(last!=-1) {
		for(int i=0; i<4; i++) {
			int nx=x+movx[i], ny=y+movy[i];
			if(!check(nx, ny)) return;

			int amx=min(last, matrix[x][y]), bmx=max(last, matrix[x][y]);
			if(!vis[amx][bmx])  {
				ans[x][y]=ans[lx][ly]=domino[amx][bmx];
					cout << "go " << nx << " " << ny << " and last domino=" << domino[amx][bmx] << endl;
				
				vis[amx][bmx]=1; vis2[nx][ny]=1; tmpflag++;
				dfs(nx, ny, -1, -1, -1);
				vis[amx][bmx]=0; vis2[nx][ny]=0; tmpflag--;
			}
		}
	}else{
		for(int i=0; i<4; i++) {
			int nx=x+movx[i], ny=y+movy[i];
			if(!check(nx, ny)) return;
			vis2[nx][ny]=1;
			dfs(nx, ny, matrix[x][y], x, y);
				cout << "go " << nx << " " << ny << " and it's half" << endl;

			vis2[nx][ny]=0;
		}
	}
}
signed main() {
	int cnt=0;
	for(int i=0; i<=6; i++) {
		for(int j=i; j<=6; j++) {
			domino[i][j]=(++cnt);
		}
	}	
	while(read()) {
		ansc=0;
		memset(vis, 0, sizeof(vis));
		memset(vis2, 0, sizeof(vis2));
		printf("Layout #%d:\n", ++data);
		for(int i=1; i<=7; i++) {
			for(int j=1; j<=8; j++) {
				printf("%d%c", matrix[i][j], ((j==8)?'\n':' '));
			}
		}	
		printf("Maps resulting from layout #1 are:\n");
		vis2[1][1]=1;
		dfs(1, 1, -1, -1, -1);
		printf("There are %d solution(s) for layout #%d.\n", ansc, data);
	}
	return 0;
} 