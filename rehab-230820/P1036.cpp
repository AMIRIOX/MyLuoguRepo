#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50;
const int maxm = 2e5+10;
int n, k, a[maxn], ans;
int prime[maxm];
void isp(){ 
	prime[0]=prime[1]=1;
	for(int i=2; i*i<=maxm; i++) {
		if(prime[i]==0) 
		for(int j=i<<1; j<=maxm; j+=i) {
			prime[j]=1;
		}
	}
};
void dfs(int ind, int al, int sum) {
	// cout << ind << " " << al << " " << sum << endl;
	if(al==k || ind==n+1) {
		// if(prime[sum]) ans++;
		if(al==k && !prime[sum]) ans++; 
	}else {
		dfs(ind+1, al+1, sum+a[ind]);
		dfs(ind+1, al, sum);
	}
}
signed main() {
	isp();
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}