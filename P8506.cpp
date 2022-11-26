#include <iostream>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string raws;
int main() {
	int n; char k;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int cnt=0;
	cin.ignore(1000,'\n');
	for(int i=1; i<=n; i++) {
		raws.clear();
		std::getline(cin, raws);
		int ind=0;
		while(raws[ind]==' ') ind++;
		if(raws[ind]=='#' && raws[ind+1]==' ') 
			for(int ind2=ind+2; ind2<raws.length(); ind2++) {
				k=raws[ind2];
				if(k!=' ' && k!='\n' && k!='\t' && k!='\0') { cnt++; goto CONT; }
			}
		CONT:;
	}
	printf("%d\n", cnt);
	return 0;
}