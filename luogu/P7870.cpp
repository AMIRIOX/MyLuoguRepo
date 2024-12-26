#include <iostream> //䣌=ude
#include <cstdio>   
#include <stack>    
using namespace std; // 䍚=using 
// 思路：栈中储存二元组[l,r] 若出栈数量v大于或小于r-l+1
// 则[l,r]分裂成[l,r-v]和[r-v+1,r]两个二元组
// typedef long long i64;
#define int long long
struct pr{   
	int l;   
	int r;   
	pr(int _l, int _r):l(_l), r(_r){}
};
stack<pr> s;
int n;
signed main() {
	scanf("%lld", &n);
	while(n--) {
		int opt;
		scanf("%lld", &opt);
		if(opt==1) {
			int l,r;
			scanf("%lld %lld", &l, &r);
			s.push(pr(l,r));
		}else {
			int k=0; scanf("%lld", &k);
			int tl=s.top().l, tr=s.top().r;
			int v, tot=0;
			while(k) {
				pr tmp = s.top(); s.pop(); // 弹出顶层二元组
				int kl=tmp.l, kr=tmp.r;
				int curv=kr-kl+1;      // 顶层二元组长度
				if(k<curv) {
					tot+=k*(kr-k+1+kr)/2;
					s.push(pr(kl,kr-k));
					k=0;
				}else {
					tot+=curv*(kl+kr)/2;	
					k-=curv;
				}
			}
			printf("%lld\n", tot);
		}
	}
	return 0;
}