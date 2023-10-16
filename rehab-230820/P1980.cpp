#include <iostream>
#include <cstdio>
using namespace std;
int n, x, ans;
signed main() {
	scanf("%d %d", &n, &x);
	for(int i=1; i<=n; i++) {
		int icpy=i;
		while(icpy) {
			if(icpy%10==x) ans++;
			icpy/=10;
		}
	}
	cout << ans << endl;
	return 0;
}