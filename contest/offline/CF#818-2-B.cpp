#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
// consturctive algorithm; implementation
int t;
char matrix[520][520];
int main() {
	// 以(r,c)为基础，上下以(k-1)长度间隔放X
	// 左偏移量-1，右偏移量+1
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--) {
		int n, k, r, c;
		cin >> n >> k >> r >> c;
		memset(matrix, '.', sizeof(matrix));
		for(int i=1; i<=n; i++) {   
			int gap=((i>=r)?(c+i-r):(c-(r-i)))%k;  //c+-abs(i-r);
			while(gap<0) gap+=k;
			for(; gap<n; gap+=k) {
				matrix[i][gap]='X';				
				// if(n==3 && i==3) cout << matrix[3][2] << endl;
			}
			if(gap==n) matrix[i][n]='X'; 
		}
		for(int i=1; i<=n; i++) {   
			for(int j=1; j<=n; j++) {
				// if(n==3 && i==2 && j==3) cout << "("<<matrix[2][3] <<")";				
				/*else*/ cout << matrix[i][j];

			}
			cout << endl;		
		}
	}
	return 0;
}