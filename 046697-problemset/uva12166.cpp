#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
// 1. 深度最大的叶子节点必须改一个才能平衡，故从叶子节点往上数
// 2. 现在问题是，改哪个使得总体更改数最少
// 2.1 是否有后效性(能否贪心)？有的
// 3. 爬爬爬，首先得注意到一个问题，天平平衡是一个整体性问题
// 也就是说，一个节点确定了，整个天平就平衡了

// r1/. 完全想歪了。首先要意识到一个问题，一个点确定了，整个天平就确定了
// r2/. 第二点，不同的天平重量一定不同，而重量可以O(1)计算。
// r3/. 出现最多次数的天平重量即根据某个节点修改整个天平的天平状态最多
// 也就是说能计算出不同节点但对应同一天平的最多节点，用sum-maxn即可
const int maxc=1e5+10;
int n, cnt[maxc]; string a;
int maxn, sum;
void dfs(int first, int last, int level) {
	int pit=0;
	if(a[first]=='[') {
		for(int i=first+1; i<=last; i++) {
			if(a[i]=='[') pit++;
			if(a[i]==']') pit--;
			// 保证面[]匹配
			if(a[i]==',' && !pit) {
				// 找叶子节点 在逗号处分割
				dfs(first+1, i-1, level+1);
				dfs(i+1, last-1, level+1);
			}
		}
	}else {
		sum++;
		int dig = 0;
		for(int i=first; i<=last; i++) {
			dig = dig*10 + a[i]-'0';
		}
		cnt[dig << level]++;
		maxn=max(maxn, cnt[dig << level]);
	}

}
int main() {
	while(cin >> n) {
		cin >> a;
		memset(cnt, 0, sizeof(cnt));
		maxn=sum=0;
		dfs(0, a.length()-1, 0);
		cout << sum-maxn << endl;
	}
	return 0;
}