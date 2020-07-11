#include <bits/stdc++.h> 
using namespace std;
string name[100];
int y[100];
int mh[100];
int d[100];
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> y[i] >> mh[i] >> d[i];
	}
	/*

	3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1

	*/
	for (int i = 0; i < n; i++) {
		int tmp = i;
		for (int j = i + 1; j < n; j++) {
			//if((y[j]<y[tmp] || y[j]==y[tmp])&&(mh[j]<mh[tmp] 
			//|| mh[j]==mh[tmp])&&(d[j]<d[tmp])){
			if ((y[tmp] > y[j]) ||
				y[tmp] == y[j] && mh[tmp] > mh[j] || 
				y[tmp] == y[j] && mh[tmp] == mh[j] && d[tmp] >= d[j]) {
				swap(y[j], y[tmp]);
				swap(name[j], name[tmp]);
				swap(mh[j], mh[tmp]);
				swap(d[j], d[tmp]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << name[i] << endl;
	}
	return 0;
}