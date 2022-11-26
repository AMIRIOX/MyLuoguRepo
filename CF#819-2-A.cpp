#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn=2500;
int t, n, xk, nmax, nmin, _nmin;
int a[maxn];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--) {
		nmax=0; nmin=114514; xk=0;
		cin >> n; 
		for(int i=1;i<=n;i++) {
			cin >> a[i];
			if(a[i]>nmax) nmax=a[i];
			if(a[i]<nmin) { _nmin=i; nmin=a[i]; }
			if(i!=1 && abs(a[i-1]-a[i])>xk) xk=abs(a[i-1]-a[i]);
		}
		if(_nmin==1) cout << nmax-nmin << endl;
		else cout << xk << endl;
	}
	return 0;
}