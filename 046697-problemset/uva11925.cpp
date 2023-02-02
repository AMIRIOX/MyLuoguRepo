// 首尾看作环，进行冒泡排序。
// 先考虑暴力，第一次显然直接把前面的都挪到最后；第二次也简单，把前两个不断交替交换、排后即可
// 但是第三个时发现交换前两个也没有用了，这时候就要将数字移动到后面了，移动结束正好还会回来
// 因此考虑到环形结构，发现操作2实际不改变环的相对位置（换句话说这里面每个元素仅相对位置有用、绝对位置没有用）
// 于是碰上两个就直接交换 由于每次正好浮上去一个数（一个数到了正确位置并放到末尾）故考虑到冒泡排序（但要每次浮到最小位置）
// 注意这里不能用冒泡排序优化：打开说这个做法其实就是每次把首位往后弹然后交换逆序对，如果优化成n-i，虽然排序上是对的
// 但是结合实际问题发现会出现前面拍好的数字不能向后弹（更不能交换了）的情况致错。
/*
3     2 1 3
	  1 2 3
3     2 3 1
4     4 2 3 1
0
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=2e5+10;
int n, a[maxn];
vector<int> ans;
signed main() {
	while(cin >> n && n!=0) {
		ans.clear();
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		for(int i=1; i<n; i++) {
			for(int j=n; j>=1; j--) {
				ans.push_back(2);
				if(j!=n && a[j]>a[j+1]) {
					swap(a[j], a[j+1]);
					ans.push_back(1);
				}
			}
		}
		for(int i=ans.size()-1; i>=0; i--) {
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
