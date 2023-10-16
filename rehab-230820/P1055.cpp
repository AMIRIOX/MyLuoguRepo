#include <iostream>
#include <cstdio>
using namespace std;
string s, d; int cnt, code;
int p(int i) { return (s[i]-'0')*(++cnt); }
signed main() {
	cin >> s;
	code = p(0) + p(2) + p(3) + p(4) + p(6) + p(7) + p(8) + p(9) + p(10);
	d=s.substr(0,12); if(code%11==10) d = d + string("X"); else d = d + char(code%11 + '0');
	cout << ((s==d)?"Right":d) << endl;
	return 0;
}