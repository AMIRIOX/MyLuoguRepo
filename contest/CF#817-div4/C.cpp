#include <iostream>
#include <cstdio> 
#include <map>
#include <cstring>
#include <vector>
// i don't fucking care about elegant
using namespace std;
map<string, int> m1;   
map<string, vector<int>> m3;
int points[4];
int main() {
	// 三个人，每个人n个单词，需要每个单词被人拥有的数目
	int t, n;
	cin >> t;
	while(t--) {
		memset(points, 0, sizeof(points));
		scanf("%d", &n);
		m1.clear(); m3.clear();
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=n; j++) {
				string k; cin >> k;
				m1[k]++;
				m3[k].push_back(i);
			}
		}
		for(map<string, int>::iterator i=m1.begin(); i!=m1.end(); i++) {
			string tn=(*i).first;
			int tm=(*i).second;
			if(tm==1) points[m3[tn][0]]+=3; 
			if(tm==2) points[m3[tn][0]]++, points[m3[tn][1]]++;
		}
		for(int i=1; i<=3; i++) printf("%d ", points[i]);
			puts("");
	}
	return 0;
}