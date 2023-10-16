// qnmddp

#include <iostream>
#include <cstdio>
using namespace std;
int n, k, ans;
void dfs(int sec, int ard, int lst) {
	if(sec==k){
		if(ard==n) ans++;
	}else for(int i=lst; ard+i*(k-sec)<=n; i++) 
		dfs(sec+1, ard+i, i);
}
signed main() {
	scanf("%d %d", &n, &k);
	dfs(0, 0, 1);
	cout << ans << endl;
	return 0;
}
