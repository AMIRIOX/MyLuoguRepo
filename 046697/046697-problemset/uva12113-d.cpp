//思路：搜索+剪枝
/*
状态：棋盘数组。
转移：新增一个正方形，计算新增后的棋盘数组
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
const int maxn=10;
char sharp; char map[maxn][maxn];
char self[maxn][maxn], copy[maxn][maxn];
const int nx=5, ny=9;
int lux[]={0, 0, 0, 1, 1, 1, 2, 2, 2};
int luy[]={0, 2, 4, 0, 2, 4, 0, 2, 4};
void put(int x, int y) {
	/*  01234
		0s_s_s
		1|sss|
		2|_s_|  */
	for(int i=0; i<=4; i++) {
		for(int j=0; j<=2; j++) {
			int curx=x+i, cury=y+j;
			if(j==2 || i==j || i+j==4) self[curx][cury]=' ';
			else if(j==1 || j==3) self[curx][cury]='_';
			else if(j==0 || j==4) self[curx][cury]='|';
			else assert(1);
		}
	}
}
bool reached()  {
	for(int i=0; i<nx; i++) {
		for(int j=0; j<ny; j++) {
			if(self[i][j]!=map[i][j]) return false;
		}
	}
	return true;
}
void dfs(int l/*第i个正方形*/, ) {
	if(l>9) return; // 最多9个，每一步都要检查
	for(int s=0; s<9; s++) {
		put(lux[s]); 

		del(luy[s]); //这个恢复怎么实现？
		// 答：用二进制而不是数组表示状态。
	}
}
void prints() {
	//debug
	for(int i=0; i<nx; i++){
		for(int j=0; j<ny; j++)
			cout << map[i][j];
		puts("");
	}
}
signed main() {
	while(fgets(map[0], 100, stdin) && map[0][0]!='0') {
		for(int i=1; i<5; i++) fgets(map[i], 100, stdin);
		
	}
	return 0;
}