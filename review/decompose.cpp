#include <iostream>
using namespace std;
int a[10010];
int decompose(int x, int a[]) {
	int cnt = 0;
	for(int i=2; i<=x/i; i++) {
		for(; x%i==0; x/=i) {
			a[++cnt] = i;
		}
	}
	if(x>1) a[++cnt]=x;
	return cnt;
}
int main(void) {
	int n;
	cin >> n;
	for(int i=1;i<=decompose(n, a); i++) {
		cout << a[i] << " ";
	}
	return 0;
}