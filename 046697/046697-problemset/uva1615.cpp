#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
struct interval {
	int l, r;
	interval(int _l=0, int _r=0): l(_l), r(_r) {}
	bool operator<(const interval& others) {
		if(this->r==others.r) return this->l > others.l;
		else return this->r < others.r;
	}
}seq[maxn];
int L, D, n, vx[maxn], vy[maxn], ans;
signed main() {
	while (cin >> L >> D >> n) {
		for(int i=1; i<=n; i++) cin >> vx[i] >> vy[i];
			ans=0;
		// 在x轴上选定一些点，
		// 对于每个点Pi(xi,yi)，在x轴上至少有一个点Ai(x,0)且0<=x<=L使得dis(Ai, Pi)<=D
		// o99999999999999999999999999999999999999999999999999 (猫踩的)
		for(int i=1; i<=n; i++) {
			int wt=sqrt(D*D-vy[i]*vy[i]);
			seq[i]=interval(vx[i]-wt, vx[i]+wt);
		}
		// n个区间[seql[i], seqr[i]]中选择最少的点使得每个区间至少有一个点。
		// 按照seqr从小到大、seql从大到小排序。每次选择最后的一个点，然后往后删除所有包含这个点的区间
		sort(seq+1, seq+1+n);
		// for(int i=1; i<=n; i++) cout << "[" << seq[i].l << ", " << seq[i].r << "]" << endl;
		int lastend=seq[1].r; 
		for(int i=1; i<=n; i++) {
			lastend=seq[i].r; ans++; 
			for(int j=i+1; j<=n; j++)
				if(seq[j].l<=lastend && seq[j].r>=lastend) i++;
				else break;
		}

		cout << ans << endl;
	}
	return 0;
}