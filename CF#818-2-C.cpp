// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int maxn=2e5+10;
// int t,n;
// int a[maxn], b[maxn];
// /*
// 每次扫描从后往前
// 1. 第一遍扫描，将每个可变的数字ai变为min(a_{i+1}+1, bi)
// 2. 第二遍扫描，将每个可变的数字ai变为min(a_{i+1}+1, bi)
// 两遍一定能结束战斗。操作本质不改变数字大小关系，但首尾除外
// 第一遍扫描已经将首项赋值为最大的情况了 无法再进一步进行

// hack:
// 2
// 2 2
// 1 3
// */
// int main() {
// 	cin >> t;
// 	while(t--) {
// 		scanf("%d", &n);
// 		memset(a, 0, sizeof(a));
// 		memset(b, 0, sizeof(b));
// 		for(int i=1; i<=n; i++) cin >> a[i];
// 		for(int i=1; i<=n; i++) cin >> b[i];
// 		bool ok = true;
// 	for(int k=0; k<2; k++)
// 		for(int i=n; i>=1; i--)
// 			if((i==n && a[i]<=a[1]) || (i!=n && a[i]<=a[i+1]))
// 				if(a[i]<=b[i]) a[i]=min((i==n)?a[1]+1:a[i+1]+1, b[i]);
// 				else {ok=false; goto PRINT;}
// 		for(int i=n; i>=1; i--) if(a[i]!=b[i]) {ok=false; break;}

// 		PRINT:
// 			printf("%s\n", ok?"YES":"NO");
// 	}
// 	return 0;
// }

// screw it

// b[i]>b[i+1]+1意味着无法传导过去。
// 思路已经很接近了，再接再厉。（妈的傻逼学了三年OI 1300难度的题都他妈不会傻逼玩意早点去死省得浪费粮食）
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int t,n;
const int maxn = 2e5+10;
int a[maxn], b[maxn];
int main() {
	cin >> t;
	while(t--) {
		scanf("%d", &n);
		// 草 memset居然被卡常了。。。非必要不要使用memset！
		for(int i=1;i<=n;i++) scanf("%d", &a[i]);
		for(int i=1;i<=n;i++) scanf("%d", &b[i]);
		bool ok=true;
		b[n+1]=b[1];
		for(int i=1;i<=n;i++) {
			if(a[i]>b[i] || (a[i]!=b[i] && b[i]>b[i+1]+1)) { ok = false; break; }
		}
		printf("%s\n", ok?"YES":"NO");
	}
	return 0;
}