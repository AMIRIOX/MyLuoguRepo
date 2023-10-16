#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100;
int n, a[maxn][maxn], lstx, lsty;
signed main() {
	scanf("%d", &n);
	a[1][n/2+1]=1;  lstx=1; lsty=n/2+1;
	for(int k=2; k<=n*n; k++) {
		if(lstx==1 && lsty!=n) {
			a[n][++lsty]=k;
			lstx=n;
		}else if(lsty==n && lstx!=1) {
			a[--lstx][1]=k;
			lsty=1;
		}else if(lstx==1 && lsty==n) {
			a[++lstx][lsty]=k;
		}else if(lstx!=1 && lsty!=n) {
			if(lstx-1>=1 && lsty+1<=n && a[lstx-1][lsty+1]==0) a[--lstx][++lsty]=k;
			else a[++lstx][lsty]=k;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}