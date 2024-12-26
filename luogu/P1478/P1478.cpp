#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s;   //n为苹果总数,s为力气
int a, b;   //a为凳子高度,b为手长
//vector<pair<int,int>> apples;
vector<pair<int, int>> lqs;
bool strict_weak_ordering(const pair<int,int> a, const std::pair<int,int> b)
{
	return a.first < b.first;
}
int main() {
	//input
	int tmp;
	int tmp2;
	cin >> n >> s;
	cin >> a >> b;
	int l = 0;
	int ap = 0;
	for (int i = 1; i <= n*2; i++) {
		if (i % 2 != 0) {
			cin >> tmp;
			continue;
		}
		if (i % 2 == 0) {
			cin >> tmp2;
			lqs.push_back(pair<int, int>(tmp2, tmp));
		}
	}
	//output test
	//cout << endl;
	//for (int i = 0; i < apples.size(); i++) {
	//	cout << apples[i] <<" "<< lqs[i] << endl;
	//}

	//模拟
	int cnt = 0;
	vector<pair<int,int>> sorted = lqs;
	sort(sorted.begin(), sorted.end(),strict_weak_ordering);
	/*for (int i = 0; i < lqs.size(); i++) {
		cout << sorted[i].first << " " << sorted[i].second << endl;
	}*/
	for (int i = 0; i < n; i++) {
		if (sorted[i].second - a <= b && s-sorted[i].first >= 0) {
			cnt++;
			s -= sorted[i].first;
		}
	}
	cout << cnt;
	return 0;
}