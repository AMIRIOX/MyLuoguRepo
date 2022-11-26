#include <iostream> 
#include <cstring>
#include <cstdio>
#include <algorithm>
#define int unsigned long long
using namespace std;
const int maxn=1e4+20;
int t,T,a[maxn];
signed main() {
	scanf("%d %d", &t, &T);
	while(T--) {
		memset(a, 0, sizeof(a));
		int n,k;
		scanf("%d %d", &n, &k);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}
		sort(a+3, a+n+1, greater<unsigned long long>());
		int ans=0;
		for(int i=1;i<=k;i++) {
			ans+=a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}