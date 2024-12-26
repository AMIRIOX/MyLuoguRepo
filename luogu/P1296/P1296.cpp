#include <stdc++.h>
using namespace std;
int cow[1000020];
//int m[1000020];
int main() {
	int n,d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> cow[i];
	}
	sort(cow, cow + n); int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cow[j]-cow[i]<=d) {
				ans++; continue;
			}				  //😘
			break;
		}
	}
	cout << ans;
	return 0;
}