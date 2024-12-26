#include <iostream>
#include <cstdio>
// sigma i<0,min(n,k)> C(n, i)
const int maxn=1e4+10;
int C[maxn][maxn];
int n,k;
long long ans=0;
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i=0; i<=n; i++) { C[i][0]=1; C[i][i]=1; }
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			C[i][j] = C[i-1][j]+C[i-1][j-1];
		}
	}
	for(int i=0; i<=min(n,k); i++) {
		ans += C[n][i];
	}
	cout << ans << endl;
	return 0;
}