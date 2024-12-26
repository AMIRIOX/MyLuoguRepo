#include <iostream>
using namespace std;
const int inf = 0x7fffffff;
int n, ans, last=-inf, x;
int main() {
	cin >> n;
	bool isf = false;
	for(int i=1; i<=n; i++) {
		cin >> x;
		if(x <= last) isf = true;
		if(isf && x>last) ans++, isf=false;
		last = x;	
	}
	cout << ans;
	return 0;
}
