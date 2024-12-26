#include <iostream>
#include <cstdio>
#include <cstring>
#define debug { cout << "fuck" << endl; }
using namespace std;
const int maxn=50;
int n, unit[maxn];
// 二分任务间隔，O(n)扫描任务表判断是否两任务之间会重合，O(nlogn)
// 补充：不能二分，同一时刻可能有多个单元处理不同任务
// 例如三个的时候，第三个和第一个的情况与第二个和第一个的冲突检查规则不一样 定死任务间隔就不行
// 另一个文档见！搜索+剪枝
bool cxk(int ivl) {
	// 任务1的时间表 unit[t]+0
	// 任务2的时间表 unit[t+ivl]
	for(int i=1; i<=n; i++) {
		if(unit[i]==unit[i+ivl] && unit[i]!=0 && unit[i+ivl]!=0) return false;
		// if(unit[i]==unit[i+ivl] && unit[i]!=0 && unit[i+ivl]!=0) {
		// 	cout << ivl << " " << i << " " << unit[i] << endl;
		// 	return false;
		// }
	}
	return true;
}
signed main() {
	// 10个程序
	while(cin >> n && n!=0) {
		memset(unit, 0, sizeof(unit));
		for(int i=1; i<=5; i++) {
			for(int j=1; j<=n; j++) {
				char c; cin >> c;
				if(c=='X') unit[j]=i;
			}
		}
		int l=0, r=50;
		while(l<r) {
			int mid=l+(r-l)/2;
			if(cxk(mid)) r=mid;
			else l=mid+1;
		}
		cout << n*10-(n-(l+1))*9 << endl;
		// cout << l;
		/*
		1234567|1234567
		XY..XX. 
		.XY.... 
		..XY...
		...XY..
		......X
		*/
	}
	return 0;
}