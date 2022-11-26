#include <iostream>
#include <cstdio>
using namespace std;
int t,T,n,m;
int main() {
	cin >> t >> T;
	while(T--) {
		scanf("%d %d", &n, &m);
		if(n==1) {
			printf("YES\n");
			for(int j=1; j<=m; j++) {
				printf("%d ",j);
			}
			puts("");
		}else if(m==1) {
			printf("NO\n");
		}else {
			printf("YES\n");
			for(int i=1;i<=n;i++) {
				printf("%d ", i);
				printf("%d ", 100-i);
				for(int j=3; j<=m; j++) {
					printf("0 ");
				}
				puts("");
			}
		}
	}
	return 0;
}