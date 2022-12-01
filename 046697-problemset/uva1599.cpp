// 妈的。感觉不如重写一遍了。
// 1. 面对节点带信息或者别的带信息，千万别忘了最朴素的数组当哈希映射的方法啊 color[node]
// 2. 写双线处理（既要执行最短路又要处理别的信息）的时候最好把队列东西取出来单独处理拓展
// 3. memset要放在初始化前面...
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1e5+10;
int n, m, d[maxn], vis[maxn];
std::vector<pair<int, int> > g[maxn];
vector<pair<int, int> > vs;
vector<int> path;
int testcnt=0;
signed main() {
	scanf("%d %d", &n, &m);
	for(int i=1;i<=m;i++) {
		int x,y,a;
		scanf("%d %d %d", &x, &y, &a);
		g[x].push_back(pair<int, int> (y, a));
		g[y].push_back(pair<int, int> (x, a));
	}
	memset(d, -1, sizeof(d));
	queue<int> q; q.push(n); d[n]=0; 
	// cout << "d[" << n << "]=" << d[n] << endl; 
	while(!q.empty()) {
		int cur=q.front(); q.pop();
		for(auto i=g[cur].begin(); i!=g[cur].end(); i++) {
			int fn=(*i).first;  
			// cout << fn << endl;
			if(d[fn]!=-1) continue;
			d[fn]=d[cur]+1;
			// cout << "d[" << fn << "]=d[" <<cur<<"]+1;" << endl; 
			// cout << "d[" << fn << "]=" << d[fn] << endl;
			q.push(fn);
		}
	}

	// for(int i=1; i<=n; i++) printf("%d ", d[i]);

	while(!q.empty()) q.pop();
	q.push(1); 
	while(!q.empty()) {
		while(!q.empty()) {
			vs.push_back(q.front());
			q.pop();
		}
		int cur=q.front(); q.pop();
		int minss=0x3f3f3f3f;
		// 题解3在这里直接把q里面的元素转移到v里面 直接用v
		// 因为后面需要两次遍历 第一次查看符合字典序要求的点 第二次拓展节点
		// 如下我不这样做的下场就是，非最小字典序的最短路和最小字典序的最短路
		// 混在一起被push进path中。懂了，寄，先睡觉了。
		// for(auto i=g[cur].begin(); i!=g[cur].end(); i++) {
		for(int i=0; i<vs.size(); i++) {
			// int fn=(*i).first;  
			int fn=vs[i];
			// cout << "(" << d[cur] << ")" << endl;
			// cout << (*i).first << " " << d[fn] << ";" << endl;
			if(d[fn]==d[cur]-1) {
				minss=min(minss, (*i).second);
			}
			// if(cur==n) minss=0;
		}
		if(minss != 0x3f3f3f3f) path.push_back(minss);
		// cout << "minss=" << minss << ": " << cur << endl;

		// 扩展结点 
		// for(auto i=g[cur].begin(); i!=g[cur].end(); i++) {
		for(int i=0; i<vs.size(); i++) {
			// int fn=(*i).first;  
			int fn=vs[i];
			if(d[fn]==d[cur]-1 && (*i).second==minss && !vis[fn]) {
				q.push((*i).first);
				if(cur==1 && fn==3) cout << testcnt++ <<endl;
				if(cur==4 && fn==3) cout << testcnt++ <<endl;
				vis[fn]=1;				
			}
		}
	}
	printf("%d\n", path.size());
	for(int i=0; i<path.size(); i++) {
		printf("%d ", path[i]);
	}
	return 0;
}