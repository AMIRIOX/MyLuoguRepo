#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e7+10;
int dp[maxn], w[maxn], c[maxn];
signed  main() {
	int t,m;
	cin >> t >> m;
	for(int i=1; i<=m; i++) {
		cin >> c[i] >> w[i];
	}
	for(int i=1;i<=m;i++) {
		for(int j=c[i]; j<=t; j++) {
			dp[j] = max(dp[j], dp[j-c[i]]+w[i]);
		}
	}
	cout << dp[t];
	return 0;
}