#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, ans, bits;
signed main() {
	scanf("%d", &n); int cpyn=n;
	while(cpyn) {
		bits++;
		cpyn/=10;
	}
	bits--;
	while(n) {
		ans+=(n%10*pow(10, bits--));
		n/=10;
	}
	printf("%d\n", ans);
	return 0;
}