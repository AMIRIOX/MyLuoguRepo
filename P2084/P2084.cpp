#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//int sti(char a) {
//	int ret;
//	istringstream iss(a);
//	iss >> ret;
//	return ret;
//}
int main() {
	int M;
	cin >> M;
	string a;
	cin >> a;
	int p = a.size()-1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '0') {
			p--;
			continue;
		}
		else {
			if (i != 0)cout << "+";
			cout << a[i] << "*" << M <<"^"<<p;
			p--;
		}
	}
	return 0;
}