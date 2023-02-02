#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#define debug {printf("------------\n");}
using namespace std;
string leaf;
string paohui;
char c;
string ans;
const int maxn=1e5+10;
int n, m, stree[maxn], xs[maxn], ask[maxn];
int taskn;
// xs：将事实层数转化成对应的傻逼题目x1标号
// ask：以事实编号排序的决策方向
int dfs(int level, int now) {
	if(level==n+1) return stree[now];
	else return dfs(level+1, (ask[xs[level]])?(now*2+1):(now*2));
	// if(level==n+1) {
	// 	printf("%d level, now=%d, arr[now]=%d\n", level, now, stree[now]);
	// 	return stree[now];
	// }else {
	// 	cout << ((ask[xs[level]])?("now*2+1"):("now*2")) << endl;
	// 	return dfs(level+1, (ask[xs[level]])?(now*2+1):(now*2));
	// }
}
signed main() {
	while(scanf("%d", &n)==1 && n!=0) {
		++taskn;
		int pow2n=(int)pow(2, n);
		ans.clear(); leaf.clear();
		memset(xs, 0, sizeof(xs));
		c=getchar();
		getline(cin, paohui);
		// cout << paohui << endl;
		int cnt=0;
		for(int i=0; i<paohui.length(); i++)
			if(paohui[i]>='0' && paohui[i]<='9') xs[++cnt]=paohui[i]-'0';

		// debug;
		// for(int i=1; i<=n; i++) cout << "第" << i << "真实层对应" << xs[i] << " ";
			// cout << endl;
		// debug;

		cin >> leaf;
		// cout << leaf << endl;
		for(int i=0; i<leaf.length(); i++) {
			// cout << "now push " << pow(2, n)+n << " node with " << leaf[i] << endl; 
			stree[pow2n+i]=leaf[i]-'0';
		}

		// debug;
		// for(int i=int(pow(2, n)); i<=int(pow(2,n))*2; i++) cout << stree[i] << " ";
		// 	cout << endl;
		// debug;

		scanf("%d", &m);
		paohui.clear();
		for(int i=1;i<=m;i++) {
			memset(ask, 0, sizeof(ask));
			cin >> paohui;
			// for(int j=1; j<=pow(2, n); j++) scanf("%1d", ask+j);
			for(int j=0; j<paohui.length(); j++) ask[j+1]=paohui[j]-'0';
			ans+=dfs(1, 1)+'0';
		}
		printf("S-Tree #%d:\n", taskn);
		cout << ans << endl;
	}
	return 0;
}