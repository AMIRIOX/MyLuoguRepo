#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 120;
char ht[maxn][maxn];
int ssx[maxn], ssy[maxn];
int oval = 0;
	int n,m; char dir;
	int sx,sy;
bool rti() {
	if(dir=='>') {
		for(int j=sy;j<=m;j++) {
			if(ht[sx][j]=='x') {
				printf("GG");
				// printf("%d %d = %c\n", sx,j ,ht[sx][j]);
				return true;
			}
		}
	}else if(dir=='^') {
		for(int i=sx;i>=1;i--) {
			if(ht[i][sy]=='x') {
				printf("GG");
				return true;
			}
		}
	}else if(dir=='<') {
		for(int j=sy;j>=1;j--) {
			if(ht[sx][j]=='x') {
				printf("GG");
				return true;
			}
		}
	}else if(dir=='v') {
		for(int i=sx;i<=n;i++) {
			if(ht[i][sy]=='x') {
				printf("GG");
				return true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d %d",&n,&m);
	getchar();
	scanf("%c", &dir);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			// scanf("%c", &ht[i][j]);
			cin >> ht[i][j];
			if(ht[i][j]=='o') {
				ssx[++oval] = i;
				ssy[oval] = j;
			}
		}
		// getchar();
	}
	if(!oval) {
		cout << "OK";
		return 0;
	}
	for(int i=1;i<=oval;i++) {
		sx = ssx[i], sy=ssy[i];
		if(rti()) return 0;
	}
	printf("OK");
	return 0;
}