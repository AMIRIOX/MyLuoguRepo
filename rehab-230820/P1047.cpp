#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5;
int trees[maxn];
int n,c,l,r, ans;
signed main() {
	cin >> n >> c;
	while(c--) {
		cin >> l >> r;
		for(int i=l; i<=r; i++) trees[i]=1;
	}
	for(int i=0; i<=n; i++) ans+=trees[i];
	printf("%d\n", n-ans+1);
	return 0;
}