#include <stdc++.h>
using namespace std;
int N, B;
int nn[20020];
int main() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> nn[i];
	}
	sort(nn, nn + N);
	int cnt = 0;
	int sum = 0;
	for (int i = N - 1, sum = 0; sum < B && i >= 0; i--) {
		cnt++;
		sum += nn[i];
	}
	cout << cnt;
	return 0;
}
