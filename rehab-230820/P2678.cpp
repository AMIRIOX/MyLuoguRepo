#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5+10;
int l,n,m, ans, rocks[maxn];
bool check(int k) {
	// 最短跳跃距离是k, 能删除m块岩石
	// 超过k的距离都得移走
	
}
signed int main() {
	cin >> l >> n >> m;
	for(int i=1; i<=n; i++) cin >> rocks[i];

	if(m==0) {

	}
	int l=1, r=1e9+10;
	while(l<r) {
		int mid=l+(r-l)/2;
		if(check(mid)) ans=mid, l=mid+1;
		else r=mid;
	}
	return 0;
}