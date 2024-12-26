#include <cstdio>
#include <iostream>
using namespace std;
int cnt[7], d;
signed main() {
	freopen("in.txt", "r", stdin);
	while(scanf("%1d", &d) && d!=0) {
		cnt[d]++;
	}
	for(int i=1; i<=6; i++) cout << "num of " << i << " : " << cnt[i] << endl;
	return 0;
}