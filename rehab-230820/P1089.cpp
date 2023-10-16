#include <iostream>
#include <cstdio>
using namespace std;
int budget[20];
int have, store;
signed main() {
	for(int i=1; i<=12; i++) {
		cin >> budget[i];
	}
	for(int i=1; i<=12; i++) {
		have = have+300-budget[i];
		if(have<0) {
			printf("-%d\n", i);
			return 0;
		}
		while(have>=100) {
			store+=100;
			have-=100;
		}
		// printf(">%d\n", have);
	}
	cout << store*1.2+have << endl;
	return 0;
}