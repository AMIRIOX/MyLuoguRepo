#define _CRT_SECURE_NO_WARNINGS
#include <stdc++.h>
using namespace std;
int p[20000005];
int main() {
	//bool ok = freopen("P1897_5.in", "r", stdin);
	//ok = freopen("P1897_5.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		//cout << endl << i <<" "<<p[i] << endl;
	}
	int ans = 0;
	sort(p, p + n); // 2 2 3 4
	//if(p[n-1]>n)ans = p[n-1] * 6 + p[n-1] * 4 + n;
	//else ans = n * 6 + n * 4 + n;
	ans = p[n - 1] * 6 + p[n - 1] * 4 + n;
	int ic = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ic++;
			continue;
		}
		if (p[i] == p[i - 1]) continue;
		else ic++;
	}
	//cout << ic << endl;
	ic *= 5;
	ans += ic;
	cout << ans;
}
