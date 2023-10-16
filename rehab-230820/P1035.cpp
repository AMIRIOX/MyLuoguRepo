#include <iostream>
#include <cstdio>
using namespace std;
double sn=0;
double ans=0, k;
signed main() {
	cin >> k;
	while(sn<=k) {
		ans++;
		sn+=(1.0/ans);
	}
	cout << ans << endl;
	return 0;
}