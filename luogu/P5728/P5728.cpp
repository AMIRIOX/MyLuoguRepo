#include <iostream>
#include <cmath>
using namespace std;
#define iyy stu[i].yy
#define isx stu[i].sx
#define iyw stu[i].yw
#define jyy stu[j].yy
#define jsx stu[j].sx
#define jyw stu[j].yw
#define sumi (iyy+isx+iyw)
#define sumj (jyy+jsx+jyw)
struct student {
	int yw;
	int sx;
	int yy;
}stu[1020];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].yw;
		cin >> stu[i].sx;
		cin >> stu[i].yy;
	}
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(iyy-jyy)<=5 && abs(iyw - jyw)<=5 && abs(isx-jsx)<=5 && abs(sumi-sumj)<=10) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 666;
}