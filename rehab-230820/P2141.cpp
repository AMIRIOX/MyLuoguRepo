#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=2e4+10;
int n, exist[maxn], ans, x, a[200], vis[maxn];
signed main() {
	cin >> n;
	for(int i=1; i<=n; i++) { cin >> a[i]; exist[a[i]]=1; }
	sort(a+1, a+n+1);
	for(int i=n; i>=2; i--) {
		for(int j=i-1; j>=1; j--) {
			if(exist[a[i]-a[j]] && a[i]-a[j]!=a[j]) {
				ans++; break;
			}
		}
	} 
	printf("%d\n", ans);
	return 0;
}