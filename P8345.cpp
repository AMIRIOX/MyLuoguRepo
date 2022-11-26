// 观察规律发现目标路径对应的ai正好单调上升
// 猜想：目标路径对应的ai正好单调上升
/* part1. 不经过S集以外的点比经过 一定更短（即i->j局部最优解就是i-j这条路）
 		i->j:    ai-2aj+c
		i->k->j: ai-2ak+c+ak-2aj+c
		即需要证明 -ak+c>=0 即c>=ak
		对于非最小值的ak的部分：
			存在aw<ak，则aw-2ak+c>=0
			那么c>=2ak-aw=ak+(ak-aw)，又因为aw<ak故ak-aw>0。
			所以c>=ak+g,g>0 => c>=ak.
		对于ak为最小值的情况：
			因为ak为最小值，那么一定存在as>ak，
			又因为对于所有不是最小值的as都有c>=as，
			所以c>=as>ak.
		Q.E.D.
   part2. 单调上升的ai aj所对应的路径就是最短简单路径
   		设S={i,j,k,...}，ai<aj<ak<...
   		i->j->k：   ai-2aj+c+aj-2ak+c
   		i->k->j：	ai-2ak+c+ak-2aj+c
		可知前者-aj-2ak一定小于后者-ak-2aj（负数绝对值越大 负数本身越小）
		推广到所有S内的元素，任取三个点i<j<k，都能得出按升序排最小
		所以整体应当升序排列
   		Q.E.D.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
int n,c,q;
int a[maxn];
signed main() {
	scanf("%d %d %d", &n ,&c, &q);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	while(q--) {
		int s;
		scanf("%d", &s);
		vector<int> v;
		while(s--) {
			int t; 
			scanf("%d", &t);
			v.push_back(a[t]);
		}
		ll sums = 0;
		sort(v.begin(), v.end());
		for(int i=0;i<v.size()-1;i++) {
			sums+=ll(v[i])-2ll*ll(v[i+1])+ll(c);
		}
		printf("%lld\n", sums);
	}

	return 0;
}