#include <iostream>
#include <cstdio>
using namespace std;
// posi为i所在的位置下标，i从1~n枚举
// 如果2posi-i-1 <=n，直接trans(i, 2posi-i-1)  若全部满足则总移动次数为n。
// 否则trans(i, posi)或(i+1, posi)，即把posi向前移动  若全部满足则移动次数为2n。
const int maxn = 1e4+10;
int T, n, a[maxn], pos[maxn];
bool flg=false; // debug flag
void d(char sign) {
	if(flg) cout << sign << ": " << endl;
}
void update(int l, int r){
	for(int i=1; i<=n; i++) {
		pos[a[i]]=i;
	}
}
void trans(int f, int g) {
	for(int i=f; i<=f+(g-f)/2; i++) {
		swap(a[i], a[i+(g-f+1)/2]);
	}
	// cout << ">";
	// for(int i=1; i<=n; i++) {
	// 	cout << a[i] << ". ";
	// }
	// cout << endl;
}
signed main() {
	cin >> T;
	while(T--) {
		scanf("%d", &n); 	
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		update(1, n);
		for(int i=1; i<n; i++) {
			int psi=pos[i];
			if(psi==i) continue;
			// cout << "--------------------------b  k:" << i << endl;
			// cout << "(" << psi << endl;
			if(2*pos[i]-i-1 <= n) {
				d('1');
				cout << i << " " << 2*psi-i-1 << endl;
				trans(i, 2*psi-i-1);
				update(i, 2*psi-i);
			}else {
				if((psi-i+1)%2==0) {
					d('2');
					trans(i, psi);
					cout << i << " " << psi << endl;
					update(i, psi+1);
						psi=pos[i];
					trans(i, 2*psi-i-1);
					cout << i << " " << 2*psi-i-1 << endl;
					update(i, 2*psi-i);
				}else {
					d('3');
					trans(i, psi+1);
					cout << i << " " << psi+1 << endl;
					update(i, psi+2);
						psi=pos[i];
					trans(i, 2*psi-i-1);
					cout << i << " " << 2*psi-i-1 << endl;
					update(i, 2*psi-i);
				}
			}
		}
	}
	return 0;
}
