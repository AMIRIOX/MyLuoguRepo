#include <bits/stdc++.h>
using namespace std;
#define isodd(x) (x&1)!=0
int main() {
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(n);
	while (n != 1) {
		if (isodd(n)) {
			n *= 3;
			n++;
			v.push_back(n);
		}
		else {
			n /= 2;
			v.push_back(n);
		}
	}
	//cout << v.size() << endl;
	for (int iv = v.size()-1; iv >= 0; iv--) {
		cout << v[iv] << " ";
	}

	//cout << n;
	return 0;
}