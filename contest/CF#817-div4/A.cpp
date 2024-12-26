#include <iostream>
#include <cstdio>
#include <cstring>
int t, ti;
using namespace std;
int main() {
	cin >> t;
	while(t--) {
		string tim;
		scanf("%d", &ti);
		cin >> tim;
		int _t=0,_i=0,_m=0,_u=0,_r=0;
		for(int i=0; i<tim.length(); i++) {
			if(tim[i]=='T') _t++;
			if(tim[i]=='i') _i++;
			if(tim[i]=='m') _m++;
			if(tim[i]=='u') _u++;
			if(tim[i]=='r') _r++;
		}
		if(_t==1 && _i==1 && _m==1 && _u==1 && _r==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}