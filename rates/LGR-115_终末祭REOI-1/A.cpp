#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int mp[60][60];
int hui[60][60];
int n,m,y,x;
string ins;
signed main() {
	cin >> n >> m >> x >> y >> ins;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			hui[i][j]=1;		
		}
	}
	for(int i=0;i<m;i++) {
		hui[x][y]=1; //因为人走到这了 重置这个位置的灰尘掉落数 不落灰
		for(int f=1; f<=n; f++) {
			for(int g=1; g<=n; g++) {
				if(f!=x || g!=y) {
					mp[f][g]+=hui[f][g];  // 除了当前位置都落灰
					hui[f][g]++;   // 计算下一分钟(i,j)位置灰尘掉落数
				}
			}
		}
		// 往下一步走
		if(ins[i]=='N' && y+1<=n){
	// cout << x << " " << y << endl;
			y++; 
		}else if(ins[i]=='S' && y-1>=1) {
	// cout << x << " " << y << endl;
			y--;
		}else if(ins[i]=='W' && x-1>=1) {
	// cout << x << " " << y << endl;
			x--;
		}else if(ins[i]=='E' && x+1<=n) {
	// cout << x << " " << y << endl;
			x++;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout << mp[j][n-i+1] << " ";
		}
		puts("");
	}
	return 0;
}