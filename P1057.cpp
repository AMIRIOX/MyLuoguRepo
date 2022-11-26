#include <iostream>
#include <cstdio>
using namespace std;
// 设f[i][j]为传了i次1球在j手上的方案数。
// 转移：f[i][j]=f[i-1][j-1]+f[i-1][j+1]
// f[m][n]
int f[100][100];
int main() {
	int n,m;
	cin >> n >> m;
	f[0][1]=1;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(j==1) 
				f[i][j]=f[i-1][n]+f[i-1][2];
			else if(j==n) {
				f[i][j]=f[i-1][n-1]+f[i-1][1];
			}else f[i][j]=f[i-1][j-1]+f[i-1][j+1];
		}
	}
	cout << f[m][1];
	return 0;
}
