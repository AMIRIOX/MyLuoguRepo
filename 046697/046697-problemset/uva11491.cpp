#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
/*
排序法的两个hack
9250670
9570
9257

925099
92599
95099
// 由此看出，排序解决是不合理的，因为原有顺序影响答案构成
// 此时模拟一遍可以看出单调栈性质：如果i<j且a_i < a_j，那么i不可能是答案
*/
const int maxn=1e5+10;
int n,d;
string ipt;
signed main(){
	while(scanf("%d %d", &n, &d) && (n!=0 || d!=0)) {
		stack<int> s; vector<int> ans;
		cin >> ipt;
		// cout << n << " " << d << " " << ipt << endl;

		s.push(ipt[0]-'0');
		for(int i=1; i<=n; i++) {
			if(i==n) {
				while(!s.empty()) { ans.push_back(s.top()); s.pop(); }
				for(int i=ans.size()-1; i>=d; i--) cout << ans[i];
					//  n-d位，
				puts("");
				break;
			}
			if(s.top()<ipt[i]-'0' && d) {
				s.pop();
				d--;
			}			
			s.push(ipt[i]-'0');
		}
	}
	return 0;
}