#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
// 思路： 
// 1. 向右下拓展
// 2. 当枚举到首位时成立
// 3. 符号作为点，方块作为边
// 4. 拓扑查有向环即可
int head[maxn], ind[maxn];
// int exist[55];
int tot;
struct edge{
	int to, v, nxt;
}g[maxn];
void addEdge(int u, int to, int v) {
	ind[to]++;
	g[++tot].to=to;
	g[tot].v=v;
	g[tot].nxt=head[u];
	head[u]=tot;
}
int n; 
string k;
signed main() {
	while(cin>> n) {
		memset(g, 0, sizeof(g)); tot=0; memset(ind, 0, sizeof(ind));
		memset(head, 0, sizeof(head));
		for(int i=1; i<=n; i++) {
			cin >> k;
			// A+00A+A+ 00B+D+A- B-C+00C+
			// a+与A+为对边，根据规则A+连A-；则A+可连向A-
			// B+与D-为对边，根据规则D-连D+；则B+可连向D+
			for(int j=0; j<k.length(); j+=2) {
				// A+ ~ Z+依次映射为1~24   //一共26个英语字母！！
				// A- ~ Z-一次映射为25~48
				for(int h=0; h<k.length(); h+=2) {
					if(h==j) continue;
					int one=0, two=0;
					if(k[j]!='0' && k[h]!='0') {
						one=k[j]-'A'+1;  
						if(k[j+1]=='-') one+=26; 

						two=k[h]-'A'+1; 
						if(k[h+1]=='-') two+=26;

						int _t = (two+26)%52;
						addEdge(one, _t, 1);
						// _t = (one+26)%52;
						// addEdge(two, _t, 1);
					}
				}
			}
		}

		//topo sort
		queue<int> q;
		int cnt=0;
		for(int u=1; u<=52; u++) if(!ind[u]) q.push(u);
		int start=q.size();
		while(!q.empty()) {
			int cur=q.front();
			q.pop(); 
			ind[cur]--;
			cnt++;
			for(int u=head[cur]; u!=0; u=g[u].nxt) {
				ind[g[u].to]--;
				if(ind[g[u].to]==0) q.push(g[u].to);
			}
		}
		if(cnt==52) printf("%s\n", "bounded");
		else printf("%s\n", "unbounded");
		// 不连通不影响拓扑排序
	}
	return 0;
}
