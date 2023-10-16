#include <iostream>
#include <cstdio>
using namespace std;
int num, price, ans=0x7fffffff;
signed main() {
	int n;
	cin >> n;
	for(int i=1; i<=3; i++) { 
		cin >> num >> price;
		int p = n/num; if(p*num < n) p++;
		ans = min(ans, p*price);  
	}
	printf("%d\n", ans);
	return 0;
}