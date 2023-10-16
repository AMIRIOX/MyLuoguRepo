#include <iostream>
#include <cstdio>
using namespace std;
int ai[2000][2000], cnt[2000];
int n, m, k;
signed main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int x; cin >> x;
			ai[x][j]++;
		}
	}
	for(int i=1; i<=k; i++) {
		int out = 0;
		for(int j=1; j<=m; j++) if(ai[i][j]) out++;
		cout << out << " ";
	}	
	cout << endl;
	return 0;
}