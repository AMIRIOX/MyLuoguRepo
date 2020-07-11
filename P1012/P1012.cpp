#include <stdc++.h>
using namespace std;
bool cmp(string a, string b) {
	/*for (int i = 0; i < ((a.length() >= b.length()) ? a.length() : b.length());i++) {
		if (a[i] != b[i]) {
			return (a[i] - '0') > (b[i] - '0');
		}
		else {
			continue;
		}
	}*/
	//(a[0] - '0') > (b[0] - '0');
	return (a + b) > (b + a);
}
int main() {
	string a[25];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n,cmp);
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	return 0;
}