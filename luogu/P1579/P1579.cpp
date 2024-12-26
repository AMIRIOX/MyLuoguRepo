#include <iostream>
using namespace std;
int n = 0;
bool isp(int num) {
	//if (num == 2) return true;
	for (int i = 2; i * i <= num;i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	cin >> n;
	if (isp(n - 4)) {
		cout << "2 2 " << (n - 4);
		return 0;
	}
	
	for (int i = 3; i < n; i++) {
		if (i % 2 != 0 && isp(i)) {
			for (int j = i; j < n; j++) {
				if (j % 2 != 0 && isp(j)) {
					if (isp(n - i - j)) {
						cout << i << " " << j << " " << (n - i - j);
						return 0;
					}
				}
			}
		}
	}

	return 0;
}