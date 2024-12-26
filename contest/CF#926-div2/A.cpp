#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int T, n, ans;
const int maxn=200;
int a[maxn];
using namespace std;

signed main() {
	cin >> T;
	while(T--) {
		memset(a, 0, sizeof(a)); ans=0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		for(int i=2; i<=n; i++) ans+=a[i]-a[i-1];
		printf("%d\n", ans);
	}
	return 0;
}