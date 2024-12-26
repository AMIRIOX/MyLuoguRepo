#include <bits/stdc++.h>
using namespace std;
struct students {
	string name;
	int y;
	int m;
	int d;
	bool operator <(students o) const {
		if (y != o.y) return y < o.y;
		if (m != o.m) return m < o.m;
		if (d != o.d) return d < o.d;
	}
};
int main() {
	students stu[120];
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name;
		cin >> stu[i].y;
		cin >> stu[i].m;
		cin >> stu[i].d;
	}
	stable_sort(stu, stu + n);
	for (int i = 0; i < n; i++) {
		cout << stu[i].name << endl;
	}
	return 0;
}