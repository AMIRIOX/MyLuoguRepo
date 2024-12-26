//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
	// freopen("p.out", "w", stdout);
	int c;
	cin >> c;
	string raw;
	cin >> raw;
	string cmd;
	
	for (int i = 0; i <= c; i++) {
		getline(cin, cmd);
		int len = cmd.length();
		if (cmd[len-1] == '\r') cmd.pop_back();
		switch (cmd[0]) {
		case '1': {
			string tmp = cmd.substr(2);
			raw += tmp;
			cout << raw << endl;
			break;
		}
		case '2': {
			int a = cmd[2]-'0';
			int b = cmd[4]-'0';
			raw = raw.substr(a, b);
			cout << raw <<endl;
			break;
		}
		case '3': {
			int a = cmd[2] - '0';
			string tmp = cmd.substr(4);
			raw.insert(a,tmp);
			cout << raw << endl;
			break;
		}
		case '4': {
			string tmp = cmd.substr(2);
			string::size_type position = raw.find(tmp);
			if (position != tmp.npos) cout << position << endl;
			else cout << -1 << endl;
			break;
		}
		}
		cmd.clear();
	}
	return 0;
}