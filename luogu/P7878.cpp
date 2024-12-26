#include <iostream> 
#include <cstring>
#include <cstdio>
#include <algorithm>
#define int unsigned long long
using namespace std;
const int maxn=1e4+20;
int t,T,a[maxn];
signed main() {
	scanf("%d %d", &t, &T);
	while(T--) {
		// 枚举i的位置（模拟k=2时的解法）
		// 1 1111 2 1212 31212
		// k=3时令i+1~n中最大的分到第三组
		// 类比 令i+1~n中第k-2大的分到第k组
		// 第三组数用堆维护
		memset(a, 0, sizeof(a));
		int n,k;
		scanf("%d %d", &n, &k);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}
		for(int i=2; i<=n;i++) {
			// 求答案

		}
	}
	return 0;
}