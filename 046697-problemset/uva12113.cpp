#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long lint;
int ltp[]={0, 2, 4, 9, 11, 13, 18, 20, 22}, edge[]={1, 3, 9, 13, 18, 19, 21, 22}, space[]={10, 11, 12, 20};
lint start=0;  int vis[20]; char map[20];
const int maxd=6; int data;
set<lint> cache;
/*
 0123456789
0 _ _ _ _ #
1|_|_|_|_|#
2|_|_|_|_|#
3|_|_|_|_|#
4|_|_|_|_|#
*/
void trans(lint& grid, int c0) {
	lint bit = 1;
	for(int i=0; i<9; i++, bit=1) if(map[i]!=' ') grid |= (bit<<(c0+i));
}
void draw(lint& node, int s) {
	int cur=ltp[s]; lint bit=1;
	for(int i=0; i<8; i++, bit=1) node |= (bit<<(cur+edge[i]));
	for(int i=0; i<4; i++, bit=1) node &= (~(bit<<(cur+space[i])));
}
void dfs(int cur, int lim, lint now) {
	if(cur==lim) {
		cache.insert(now);
		return;
	}
	for(int i=0; i<9; i++) {
		if(vis[i]) continue;
		lint restore=now;
		vis[i]=1; draw(now, i);
		dfs(cur+1, lim, now);
		vis[i]=0; now=restore;
	}
}
signed main() {
	for(int i=1; i<=maxd; i++) dfs(0, i, 0);
	while(fgets(map, 100, stdin) && map[0]!='0') {
		if(map[0]==0) break;
		start=0;
		trans(start, 0);
		for(int i=1; i<5; i++) {
			fgets(map, 100, stdin);
			trans(start, i*9);
		}
		printf("Case %d: ", ++data);
		if(cache.count(start)==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}