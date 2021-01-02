#include <iostream>
using namespace std;
int n,a[100010];
void dfs(int cur) {
	if(cur==n) {
		for(int i=0;i<n;i++) cout << a[i] << " ";
		cout << endl;
		return;
	}
	for(int i=1;i<=n;i++) {
		bool ok=true;
		for(int j=0;j<cur;j++) {
			if(i==a[j]) ok=false;
		}
		if(ok) {
			a[cur]=i;
			dfs(cur+1);
		}
	}
}
int main() {
	cin >> n;
	dfs(0);
	return 0;
}