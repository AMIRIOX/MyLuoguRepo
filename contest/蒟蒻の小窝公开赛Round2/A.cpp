#include <iostream>
#include <cmath>
#define int long long
using namespace std;
const int inf = 0x7fffffff;
int k,n,m,T,maxn;
int gcd(int x, int y) {
	return y?gcd(y,x%y):x;
}
signed main() {
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i=1;i<=10000000;i++) {
			maxn=-inf;
			if(maxn < max(maxn, gcd(abs(i-n), abs(i-m)))) {
				k=i;
				maxn = max(maxn, gcd(abs(i-n), abs(i-m)));
			}
		}
		cout << k;
	}
	return 0;
}