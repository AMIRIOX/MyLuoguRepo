#include <iostream>
using namespace std;
int main() {
	double step;
	int s, x;
	cin >> s >> x;
	double Begin =(double)s - (double)x;
	double End = (double)s + (double)x;
	double ind;
	for (step=7.0,ind=0; ;step *= 0.98,ind += step) {
		if (ind >= Begin) {
			if ((ind + step * 0.98) > End) {
				cout << 'n';
			}
			else {
				cout << 'y';
			}
			return 0;
		}
	}
	return 0;
}