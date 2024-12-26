//绿书给的代码有问题，没有考虑一个任务的保留表在某一时刻需要多个单元的情况。 我改了一下才过。陈锋超小杯，微软超小杯，我超大杯，爆杀微软员工

#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;
const int maxn=20+1, UNIT=6, maxp=10;
int sys[UNIT][maxn*maxn], ansf[maxp+2];
vector<int> task[maxn];
vector<int> dist; int n;
inline bool canPut(int clock) {
	// 能否在clock时间安排一个任务
	for(int i=1; i<=n; i++) for(int j=0;j<task[i].size();j++) if(sys[task[i][j]][clock+i]) return false;
	return true;
}
inline void put(int clock) {
	for(int i=1; i<=n; i++) for(int j=0;j<task[i].size();j++) sys[task[i][j]][clock+i]=1;
}
inline void del(int clock) {
	for(int i=1; i<=n; i++) for(int j=0;j<task[i].size();j++) sys[task[i][j]][clock+i]=0;
}
void dfs(int t, int T, int clock/*last task start time*/, int& ans) {
	if(t==T) {
		ans=min(ans, clock+n);
		return;
	}
	for(auto D: dist){
		int nc=clock+D;
		if(nc+ansf[T-t] >= ans) break;
		if(canPut(nc)) {
			put(nc);
			// cout << t << " tryin'" << D << ", now is " << nc << endl;
			dfs(t+1, T, nc, ans);
			del(nc);
		}
	}
}

signed main() {

	while(cin >> n && n!=0) {
		memset(sys, 0, sizeof(sys));
		for(int i=1; i<maxn; i++) task[i].clear();
		memset(ansf, 0, sizeof(ansf));
		dist.clear();
		for(int i=1; i<=5; i++) {
			for(int j=1; j<=n; j++) {
				char c; cin >> c;
				if(c=='X') task[j].push_back(i);
			}
		}
		put(0);	
		for(int i=0; i<=n; i++) if(canPut(i)) dist.push_back(i);
		ansf[1]=n;
		for(int i=1; i<=maxp; i++) {
			ansf[i]=n*i;
			dfs(1, i, 0, ansf[i]);
		}
		cout << ansf[maxp] << endl;
	}
	return 0;
} 