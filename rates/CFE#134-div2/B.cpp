#include <iostream>
#include <cstdio>
using namespace std;
int w;
int n,m,sx,sy,d;
int main() {
	scanf("%d", &w);
	while(w--) {
		scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &d);
		bool ok=false;
		if(sx-d>1 && sy+d<m) ok=true;
		if(sx+d<n && sy-d>1) ok=true;
		if(!ok) printf("-1\n");
		else printf("%d\n", n+m-2);
	}
	return 0;
}