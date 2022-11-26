#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
const int maxn=1e6+10;
const int maxv=1e9+10;
// 思路：两个单调栈
// ls负责找出对于每个信号塔，其左侧接受它信号的信号塔位置
// rs负责找出对于每个信号塔，其右侧接受它信号的信号塔位置
// 每次找到位置，都ans[pos]+=v[i]; (i为当前信号塔位置，pos为接收塔位置)
stack<int> ls;
stack<int> rs;
int n, h[maxn], v[maxn];
int ans[maxn];
int main() {
	cin >> n;
	for(int i=1;i<=n;i++) {
		scanf("%d %d", &h[i], &v[i]);
	}
	// ls发挥作用
	for(int i=1;i<=n;i++) {
		while(!ls.empty() && h[ls.top()]<=h[i]) ls.pop();
		int ansl = ls.empty()?0:ls.top();
		ans[ansl]+=v[i];
		ls.push(i);
	}
	// rs发挥作用
	for(int i=n;i>=1;i--) {
		while(!rs.empty() && h[rs.top()]<=h[i]) rs.pop();
		int ansr = rs.empty()?0:rs.top();
		ans[ansr]+=v[i];
		rs.push(i);
	}
	int maxans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) {
		if(ans[i]>maxans) maxans=ans[i];
	}
	cout << maxans << endl;
	return 0;
}