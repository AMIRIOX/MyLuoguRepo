#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=20000;
int ans[maxn], n;
signed main() {
	cin >> n;
	for(int i=1; i<=n; i++) ans[i]=1;

	for(int i=2; i<=n; i++){
		for(int j=1; j<=i/2; j++) ans[i]+=ans[j];
	}	
	cout << ans[n] << endl;
	return 0;
}
