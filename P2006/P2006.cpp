#include <iostream>
using namespace std;	
int main() {
	int k, m, n;
	cin >> k >> m >> n;
	int a, b;
	bool flg = false;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if ((!a && b) || a&&(k/a)*b >= n) {
			cout << i << " ";
			flg = true;
		}
	}
	if (!flg)cout << "-1";
	return 0;
}