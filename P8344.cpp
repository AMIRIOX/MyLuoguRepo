#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
signed main() {
	int T;
	cin >> T;
	while(T--) {
		int x,y,z;
		scanf("%lld %lld %lld", &x, &y, &z);
		// x>=z && z-1+z-2+z-3+...+z-x >= y
		int ytx=(1+x)*(x/2);
		if(x%2) ytx += (x/2+1);
		//int maxcus=z*x-ytx;
		// int maxcus=z*x-ytx+z;
		int maxcus=z*x-ytx+(z-x);
		if(x<=z && maxcus>=y) printf("Renko\n");
		else printf("Merry\n");
	}
	return 0;
}