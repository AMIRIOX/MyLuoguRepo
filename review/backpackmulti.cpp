#include <iostream>
using namespace std;
const int maxn = 100010;
int dp[maxn], w[maxn], c[maxn];
int n,W;
int main() {
	cin >> n >> W;
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		int vi, wi, mi;
		cin >> vi >> wi >> mi;
		for(int cx=1; mi>=cx; cx<<=1) {
			mi-=cx;
			w[++cnt] = vi*cx; 
			c[cnt] = wi*cx;
		}
		if(mi) {
			w[++cnt] = vi*mi;
			c[cnt] = wi*mi;
		}
	}
	for(int i=1; i<=cnt; i++) {
		for(int j=W; j>=c[i]; j--) {
			dp[j] = max(dp[j], dp[j-c[i]]+w[i]);
		}
	}
	cout << dp[W];
	return 0;
}