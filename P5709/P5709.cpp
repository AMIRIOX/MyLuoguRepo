#include <iostream>
using namespace std;
int main() {
	int m, t, s;
	cin >> m >> t >> s;
	int ans;
	if (s % t == 0)
		ans = m-s/t;
	else 
		ans = m-1-s/t;
	cout << ((ans >= 0) ? ans : 0);
	return 0;
}