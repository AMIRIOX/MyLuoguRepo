#include <iostream>
#include <cstdio>
using namespace std;
int ans, apples[20];
signed main() {
	for(int i=1; i<=11; i++) cin >> apples[i];
	for(int i=1; i<=10; i++) if(30+apples[11] >= apples[i]) ans++;
	printf("%d\n", ans);
	return 0;
}