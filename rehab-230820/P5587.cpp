#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=20000;
string text1[maxn], text2[maxn];
string rd;
int cnt1, cnt2;
double rht, minu;
signed main() {
	while(rd!="EOF") {
		getline(cin, rd);
		++cnt1;
		for(int i=0; i<rd.length(); i++) {
			if(rd[i]=='<') { if(!text1[cnt1].empty()) text1[cnt1].pop_back(); }
			else text1[cnt1].push_back(rd[i]);
		}
	}
	rd.clear();
	while(rd!="EOF") {
		getline(cin, rd);
		++cnt2;
		for(int i=0; i<rd.length(); i++) {
			if(rd[i]=='<') { if(!text2[cnt2].empty()) text2[cnt2].pop_back(); }
			else text2[cnt2].push_back(rd[i]);
		}
	}
	
	cnt1--; cnt2--;
	for(int i=1; i<=cnt1; i++)
		for(int ind=0; ind<min(text1[i].length(), text2[i].length()); ind++)
			if(text1[i][ind]==text2[i][ind]) rht++;
	cin >> minu;
	printf("%.0f", rht/(minu/60.0));
	return 0;
}