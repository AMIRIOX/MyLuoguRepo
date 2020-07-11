#include <iostream>
using namespace std;
int dtx[10020];
int dty[10020];
int xl[10020];
int yl[10020];
int main() {
	int n;
	cin >> n;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> dtx[i];
		cin >> dty[i];
		cin >> xl[i];
		cin >> yl[i];
	}
	int x, y;
	cin >> x >> y;
	for (int i = n - 1; i >= 0; i--) {
		if ((dtx[i] <= x && x <= dtx[i] + xl[i]) && (dty[i] <= y && y <= dty[i]+yl[i])) {
			cout << i + 1;
			flag = true;
			break;
		}
	}
	if (!flag) cout << -1;
	return 0;
}