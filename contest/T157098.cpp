#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e6+10;
const int mod = 998244353;
int a[maxn], n, p, ans;


int quickpower2(int a, int n) {
	if(n==0) return 1;
	if(a==0) return 0;
    int ans = 1;
    while (n) {
        if (n & 1) ans *= a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

void printBinarySet(int S) {
	int all_things_we = 0;
    for (int i = 0; i < n; i++) {
        if (S & (1 << i)) all_things_we += a[i];
    }
    int tmp = quickpower2(p, all_things_we);
    ans= (ans+tmp)%mod;
}
void printSubsetByBinary() {
    for (int i = 0; i < (1 << n); i++) {
        printBinarySet(i);
    }
}

signed main() {
	cin >> n >> p;
	if(p==0) {
		cout << 1 << endl;
		return 0;
	}
	for(int i=0;i<n;i++) cin >> a[i];
	printSubsetByBinary();
	cout << ans%mod;
	return 0;
}