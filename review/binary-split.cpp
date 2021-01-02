#include <iostream>
using namespace std;
int main() {
	int k = 0;
	cin >> k;
	for(int c=1; k>=c; c<<=1) {
		k-=c;
		cout << c << " ";
	}
	if(k) cout << k << endl; 
	return 0;
}