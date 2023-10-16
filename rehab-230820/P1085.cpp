#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int t1, t2, ans, ansc, flg;
signed main() {
	for(int i=1; i<=7; i++) {
		cin >> t1 >> t2;
		if(t1+t2 > 8 && t1+t2>ansc) {
			flg=1;
			ans=i; ansc=t1+t2;
		}
	}
	if(!flg) printf("0\n");
	else {
		cout << ans << endl;
	}
	return 0;
}