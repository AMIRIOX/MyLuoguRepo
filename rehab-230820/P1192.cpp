#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define int long long
const int maxn=1e5+20;
int n, k, ans[maxn];
const int p=100003;
signed main() {
	scanf("%d %d", &n, &k);
	ans[0]=ans[1]=1;
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=min(k, i); j++) {
			ans[i]=(ans[i]+ans[i-j])%p;
		}
	}
	cout << ans[n] << endl;
	return 0;
}