#include <iostream> 
#include <cstdio>
#include <cstring>
#include <cstring>
using namespace std;
int n;
int a[500];
string x;
signed main() {
	scanf("%d", &n);
	int t=0, cnt=0;
	for(int i=1; i<=n; i++) {
		memset(a, 0, sizeof(a));
		cnt=0;
		cin >> x;
		for(int j=0;j<2;j++) { if(!a[x[j]-'a']){cnt++;} a[x[j]-'a']++;}
		x.clear();
		cin >> x;
		for(int j=0;j<2;j++) { if(!a[x[j]-'a']){cnt++;} a[x[j]-'a']++;}
		printf("%d\n", cnt-1);
		x.clear();
	}
	return 0;
}