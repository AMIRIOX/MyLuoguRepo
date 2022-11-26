#include <iostream>
#include <cstdio>
using namespace std;
int t, n;
long long ans;
int main() {
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		string k; cin >> k;
		ans=0;
		for(int i=0; i<k.length(); i++) {
			if(k[i]=='L') {
				ans+=i;
			}else {
				ans+=(n-i-1);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}