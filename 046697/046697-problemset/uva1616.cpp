#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n; const int maxn = 1e5+10;
const double eps=1e-7;
int gcd(int x, int y) {
	return y?gcd(y, x%y):x;
}
struct interval{
	int l, r;
	interval(int _l=0, int _r=0):l(_l), r(_r) {}
	bool operator<(const interval& oth) {
		if(this->l == oth.l) return this->r < oth.r;
		else return this->l < oth.l;
	}
}seq[maxn];
int dcmp(double x) { return ( fabs(x)<=eps ? 0 : ( x>0 ? 1 : -1) ); }
int dcmp(double a, double b) { return dcmp(a-b); }
bool check(double len) {
	// cout << "checking ans=" << len << endl; 
	// double lb=min(); // 第一个也不一定能放下...
	double lb=0;
	for(int i=1; i<=n; i++) {
		lb=max((double)seq[i].l, lb)+len;

		// cout << "current start: " << lb << ", length= " << len << ", so to next point " << seq[i].r << " is ok" << endl;
		// if(max((double)seq[i].l, lb)+len > seq[i].r) return false;
		if(lb > seq[i].r) {
		// cout << i << ": current start: " << lb << ", length= " << len << ", so to next point " << seq[i].r << " is bad" << endl;
			return false;
		}
	}
	return true;
}
void output(double ans) {
	double down=floor(ans+eps);
	if(dcmp(ans, down)==0) {
		printf("%.0lf/1\n", ans);
		return;
	}
	double rtnf=1; int p=1, q=1;
	for(int i=0; i<=n; i++) {
		int son = (int)floor((double)i*ans+0.5);
		double x = (double)son/i;
		// if(i==2) cout << fabs(x-ans) << " " << fabs(rtnf-ans) << endl;
		if(fabs(x-ans) < fabs(rtnf-ans)) {
			rtnf=x; // 不是ans！以后不要起这么傻逼有歧义的名字
			p=son;
			q=i;
		}
	}
	int o=gcd(p,q);
	printf("%d/%d\n", p/o, q/o);
}
signed main() {
	/* 输入n条线段，把每条线段变成原线段的一条子线段，使得改变后所有线段等长且不相交（但是端点可以重合）。输出最大长度（用分数表示）。*/
	while(cin >> n) {
		for(int i=1; i<=n; i++) {
			int jdhak,asdkas;
			scanf("%d %d", &jdhak, &asdkas);
			seq[i].l=jdhak; seq[i].r=asdkas;			
		}
		sort(seq+1, seq+1+n);
		double l=0, r=1e6/n;  int cnt=0;
		while(l<r) {
			if(++cnt>50) break;
			double mid=l+(r-l)/2.0;
			// cout << "testing " << l << " " << r << "with middle point: " << mid << endl;
			if(check(mid)) l=mid; 
			else r=mid;
		}
		output((l+r)/2.0);
		// cout << l << " " << r << endl;
	}
	return 0;
}

// 1. 精度要求较高的二分题目不加一
// 2. 起变量名要避免歧义防止出事，比赛时可以静态差错
// 3. 搞清楚脑子里的逻辑再实现函数