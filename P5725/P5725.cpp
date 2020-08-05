#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int maxn = n * n;
	for (int i = 1; i <= maxn; i++) {
		cout << setw(2) << setfill('0') << i;
		if (i % n == 0)cout << endl;
	}
	cout << endl;
	int whiteSpace=1;
	int row = 1;
	int cntnum = 1;
	while (whiteSpace>0) {
		whiteSpace = n*2-row * 2;
		for (int i = 0; i < whiteSpace; i++) {
			cout << " ";
		}
		for (int i = 0; i < row; i++) {
			cout << setw(2) << setfill('0') << cntnum++;
		}
		row++;
		//cout << "   (" << whiteSpace << ")  ";
		//cout << "   (" << row << ")  ";
		cout << endl;
	}
	return 0;
}