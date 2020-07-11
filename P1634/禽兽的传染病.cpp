#include <iostream>
using namespace std;
int main(){
	typedef long long LL;
	LL n;
	LL x;
	cin >> x >> n; 
	LL qs = 1;
	for(int i=0;i<n;i++){
		qs=qs+qs*x;
	}
	cout << qs;
	return 0;
} 
