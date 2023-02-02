#include <iostream>
#include <cstdio>
#include <cmath>
#define debug {printf("-------\n");}
using namespace std;
const int maxn=100;
int adv[maxn][maxn], ans[maxn*maxn];
int M[20]={1};
int n;  const int NW=1, NE=2, SW=3, SE=4;
bool allblack(int _x, int _y, int _n) {
	for(int i=_x; i<=_x+_n-1; i++) {
		for(int j=_y; j<=_y+_n-1; j++) {
	if(_x==5 && _y==7 &&_n==2)
	{
		cout << i << "," << j << "==" << adv[i][j] << endl;
	}
			if(!adv[i][j]) return false;
			// if(!adv[i][j]) {
				// printf("check %d,%d size %d; white: %d,%d\n", _x, _y, _n, i, j);
			// 	return false;
			// }
		}
	}
		// cout << _x << " " << _y << " " << _n << endl;
	return true;
}
void trans1(int x, int y, /*左上角*/ int curn, int calced, int level, string test) {
	// int bits = n/curn/2-1;
	if(curn==1 || allblack(x, y, curn)) {
		// if(adv[x][y]) ans[(x-1)*n+y]=calced+f*pow(5, bits);
		if(adv[x][y]) {
			ans[(x-1)*n+y]=calced;
			// printf("+%d*pow(5, %d)=%d\n", f, bits, ans[(x-1)*n+y]);
			cout << test << " =" <<  calced << endl;

		if(calced==19) cout <<x  << " " << y  << " " << curn<< endl;
			debug
		}
	} else { 
		trans1(x+curn/2, y+curn/2, curn/2, calced+SE*M[level],level+1, test+string("+SE"));
		trans1(x, y, curn/2, calced+NW*M[level], level+1, test+string("+NW"));
		trans1(x, y+curn/2, curn/2, calced+NE*M[level], level+1, test+string("+NE"));
		trans1(x+curn/2, y, curn/2, calced+SW*M[level], level+1, test+string("+SW"));
	}
	return;
}
signed main() {
	for(int i=1; i<20; i++) {
		M[i]=M[i-1]*5;
	}

	while(cin >> n) {
		if(n>0) {
			int x=0, cnt=0;
			while(scanf("%1d", &x)==1) {
				++cnt;
				if(cnt%n==0) adv[cnt/n][n]=x;
				else adv[cnt/n+1][cnt%n]=x; 
				// printf("%d %d %d\n", cnt/n+1, cnt%n, x);
			}
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					cout << adv[i][j] << " ";
				}
				cout << endl;
			}
			memset(ans, 0x3f3f3f3f, sizeof(ans));
			trans1(1+n/2, 1+n/2, n/2, SE, 1, "SE");
			trans1(1, 1, n/2, NW, 1, "NW");
			trans1(1, 1+n/2, n/2, NE, 1, "SW");
			trans1(1+n/2, 1, n/2, SW, 1, "NE");
			for(int i=1; i<=n*n; i++) if(ans[i]!=0x3f3f3f3f) cout << ans[i] << endl;
		}else {
			printf("todo: negative\n");
		}
	}
	return 0;
}