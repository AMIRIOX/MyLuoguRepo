#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1e5+10;
int n, m, d[maxn], vis[maxn];
std::vector<pair<int, int> > g[maxn];
signed main() {
	scanf("%d %d", &n, &m);
	for(int i=1;i<=m;i++) {
		int x,y,a;
		scanf("%d %d %d", &x, &y, &a);
		g[x].push_back(pair<int, int> (y, a));
	}
	queue<int> q; q.push_back(n); d[n]=0; 
	memset(d, 0x3f3f3f3f, sizeof(d));
	while(!q.empty()) {
		int cur=q.front(); q.pop();
		vis[cur]=1;
		for(auto i=g[cur].begin(); i!=g[cur].end(); i++) {
			int fn=*i.first;  
			d[fn]=max(d[fn], d[cur]+1);
			if(!vis[fn]) q.push_back(fn);
		}
	}
	while(!q.empty()) q.pop();
	q.push_back(1);
	while(!q.empty) {
		int cur=q.front(); q.pop();
		for(auto i=g[cur].begin(); i!=g[cur].end(); i++) {
			int fn=*i.first;  
			if(d[fn]==d[cur]+1) 
		}
	}
	.. //颜色考虑
	return 0;
}