#include <iostream>
#include <map>
using namespace std;
map<char, int> box;
bool isp(int num) {
	if (num < 2) return false;
	if (num == 2) return true;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}
int main() {

	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (box.find(a[i]) != box.end()) {
			box[a[i]]++;
		}
		else {
			box.insert(make_pair(a[i],1));
		}
	}
	map<char, int>::iterator ibv = box.begin();

	ibv = box.end();
	ibv--;

	int Maxn = INT_MIN;
	int Minn = INT_MAX;
	for (int i = 0;i<box.size();i++) {
		if (box[i] != 0) {
			Maxn = box[i] > Maxn ? box[i] : Maxn;
			Minn = box[i] < Minn ? box[i] : Minn;
		}
	}
	int res = Maxn - Minn;
	bool flag = isp(res) ? true : false;
	cout << (flag ? "Lucky Word" : "No Answer") << endl;
	cout << (flag ? res : 0);
}

