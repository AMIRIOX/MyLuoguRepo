#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
// 题意：原有若干根长度为l的木棍，砍成k段长度为a1~ak，求原始木棍长度l最小值
// 思路：从小到大枚举原始木棍长度，用dfs搜索看是否能用k根现有木棍拼出原有木棍
// dfs搜索策略：枚举k根现有木棍，对于每根当前正在拼的原始木棍
// “试试”找到一个还没用过的、可以拼进去的现有木棍拼进去（枚举状态：选或不选）；
// 到最后全部用完时正好拼完若干根l长的木棍则成功 拼不完就只好回溯到上一个“尝试”选完的木棍
// 可行性剪枝：ok1. 如果当前木棍长度不可用，那么大于等于它的木棍长度都不可用，直接跳到刚好比他大的位置
//	   		  ok2. 已经拼凑好了所有木棍就直接退出 (所有木棍数量：sigma(ai)/D)
//			  ok3. 如果 D|sigma(ai) 不成立，则直接跳过D，去搜D+1
//		      ok4. D从max(ai)枚举到sigma(ai)/2。（前者：原始木棍长度不可能短于当前木棍长度；后者即sigma(ai)/D>=2，否则原木棍只有一条)
// 			  ok5. 如果当前在拼的原始木棍剩下的长度和当前木棍长度相等，往后拼却失败了（回溯回来了），那么直接回溯，不需要往下再搜了
//				// 当前木棍最佳方案肯定是拼到当前在拼的原始木棍的剩余空缺里(因为它后面的木棍都更短更有价值，应该用它自己即最大的)
//				// 最佳方案是这样，那么无论怎么搜都超不过这个方案，既然最优方案都失败了，那肯定是前面拼的不对。
//			  ok6. 如果当前在拼的原始木棍剩下长度等于原长D,却拼失败了,就回溯改之前的.
//				// 因为当前在拼的原始木棍是空的,所有空的原始木棍等效;所以当前这根木棍一定会用上,但却发现拼不上,所以前面肯定错了
//				// 假设D=10, 还剩6 5, 拼失败了(即剩余木棍没法拼出10的整数倍且不剩余),所以前面一定有文艺 

// 最优性剪枝/优化搜索顺序：ok1. 从最长的木棍开始“尝试”选（每次选要判断其是否被选定过），减少回溯次数（短木棍可以拼凑更多零头，更有价值）
const int maxn=100;
int n, m, tn, sum, length[maxn], D;
int mind=2147483600, maxd=-2147483600;
// 5 2 1 5 2 1 5 2 1
// 5 5 5 2 2 2 1 1 1

void dfs(int cur, int last, int rest) { // 当前在拼到第几根原始木棍了|上一根构成本木棍一部分的当前木棍/*位置*/长度|当前原始木棍还剩多少要拼|还剩下的可用木棍数
	if(cur==m /*&& !rest*/) {
		if(rest) printf("%d\n", rest);
		else printf("%d\n", D);
		exit(0);
	}
	if(!rest) dfs(cur+1, maxd, D); 
	else// for(int i=last; i<=tn; i++) {
		for(int i=last; i>=mind; i--){
			if(length[i] && i<=rest) {
				length[i]--;
				dfs(cur, i, rest-i);
				length[i]++;
				if(!rest || rest==i || rest==D) return;
			}
		}
}
int main() {
	scanf("%d", &n);
	int tmp;
	for(int i=1;i<=n;i++) {
		scanf("%d", &tmp);
		if(tmp>50) continue;
		sum+=tmp;
		length[tmp]++;
		if(mind>tmp) mind=tmp;
		if(maxd<tmp) maxd=tmp;
	}
	// sort(a+1,a+tn+1,[&](const int& a, const int& b) {return a > b; });
	for(D=maxd; D*2<=sum; D++) {
		if(sum%D) continue;
		m=sum/D;
		dfs(1,maxd,D);
		// if(ok) { printf("%d\n", D); return 0; }
	}
	printf("%d\n",sum);
	return 0;
}
