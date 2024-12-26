#include <iostream> 
#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
有一种包裹能装的体积是V，每个包裹只能装两件物品，现在给出n件物品，问最少要使用多少包裹去装那n件物品？
input
第一行一个T，表示几组数据，接下来有一行换行。每组数据第一行是n(0 -- 1e51e5)，表示有几件物品，接下来n行表示v_i
最后一行是包裹的容量。每两组数据之间也有一个回车。
output
最少需要的包裹数。每两组之间有一个回车
*/
const int maxn=1e5+10;
int T, n, pack[maxn], ps;
signed main() {
	cin >> T;
	while(T--) {
		memset(pack, 0, sizeof(pack));
		scanf("%d %d", &n, &ps);
		for(int i=1; i<=n; i++) scanf("%d", &pack[i]);
		sort(pack+1, pack+n+1);
		int i=1, j=n, ans=0;
		while(i<j) {
			if(pack[i]+pack[j]<=ps) {i++; j--; ans++;}
			else {j--; ans++;}
		}
		if(i==j) ans++; 
		cout << ans << endl << endl;
	}
	return 0;
}