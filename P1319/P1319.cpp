#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
	int N;
	cin >> N;
	int tmp = 0,cnt=0;
	while (tmp < N * N) {
		cin >> arr[cnt];
		tmp += arr[cnt];
		cnt++;
	}
	int cnt2 = 0;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 0; j < arr[i-1]; j++) {
			if (cnt2 == N) {
				cout << endl;
				cnt2 = 0;
			}
			cout << ((i % 2 == 0) ? '1' : '0');
			cnt2++;
		}
	}
	return 0;
}