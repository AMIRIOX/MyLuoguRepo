#include <iostream>
#define int long long
using namespace std;

int quickpower(int a, int n) {
	if(n==0) return 1;
	else if(n%2==1) return quickpower(a,n-1)*a;
	else {
		int temp = quickpower(a,n/2);
		return temp*temp;
	}
}
int quickpower2(int a, int n) {
	int ans = 1;
	while(n) {
		if(n&1) ans*=a;
		a=a*a;
		n>>=1;
	}
	return ans;
}
signed main() {
		int di, mi;
		cin >> di >> mi;
		cout << quickpower(di,mi) << ' ' << quickpower2(di,mi);
		return 0;
}
