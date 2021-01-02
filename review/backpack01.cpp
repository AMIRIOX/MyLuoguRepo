#include <iostream>
using namespace std;
const int maxn = 10010;
int dp[maxn], c[maxn], w[maxn];
int main() {
	int T,M;
	cin >> T >> M;
	for(int i=1;i<=M;i++) {
		cin >> c[i] >> w[i];
	}
	for(int i=1; i<=M; i++) {
		for(int j=T; j>=c[i]; j--) {
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		}
	}
	cout << dp[T];
}