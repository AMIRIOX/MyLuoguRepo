#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5+10;
int a[maxn],dp[maxn];
// dp[i] = max(0,dp[i-1])+a[i];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
	}
	for(int i=1;i<=n;i++) {
		dp[i]=max(0, dp[i-1]) + a[i];
	}
	int ans = -0x7fffffff;
	for(int i=1;i<=n;i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}