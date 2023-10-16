#include <iostream>
#include <cstdio>
using namespace std;
long long ai[200], cnt;
signed main() {
	while(cin>>ai[++cnt] && ai[cnt]!=0);
	for(int i=cnt-1; i>=1; i--) cout << ai[i] << " ";
	return 0;
}