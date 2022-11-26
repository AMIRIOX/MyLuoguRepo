#include <iostream>
#include <cstdio>
using namespace std;
double a,b;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	int enums=int(b/a);
	cout << (double)enums/b << endl;
	return 0;
}