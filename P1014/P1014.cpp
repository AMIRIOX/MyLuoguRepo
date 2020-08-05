#include <iostream>
using namespace std;
int x = 1;
int y = 1;
void getans(int& x, int& y) {
	if (((x+y) % 2) == 0) {
		y += 1;
		if (x == 1) return ;
		else x -= 1;
	}
	else {
		x += 1;
		if (y == 1)return;
		else y -= 1;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		getans(x, y);
	cout << x << "/" << y <<endl;

	return 0;
}