// 我草，怎么这么多种情况，烦哎
// 思维混乱了 以下数据是过了 不管了
/*
2
AA
AB
2
AAA
AC
2
AAA
ABA
2
AAZZAA
AB
2
AAZZA
AB
4
FRED
SAM
JOE
MARGARET
2
FRED
FREDDIE
2
JOSEPHINE
JERRY
2
LARHONDA
LARSEN
2
AZ
B
0
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n;
const int maxn=1e3+10;
string ipt[maxn];
signed main() {
	while(scanf("%d", &n)==1 && n!=0) {
		for(int i=0; i<n; i++) cin >> ipt[i];
		sort(ipt, ipt+n);
		int midl=n/2-1, midr=n/2;
		bool ok=false;
		for(int i=0; i<min(ipt[midl].length(), ipt[midr].length()); i++) {
			if(ipt[midl][i]!=ipt[midr][i]) {
				if(i==ipt[midr].length()-1 && i==ipt[midl].length()-1) cout << "case1: " << ipt[midl] << endl;
				else if(ipt[midr].length() < ipt[midl].length()) {
					string ans; int j;
					for(j=0; j<ipt[midl].length();j++) 
						if((j<ipt[midr].length() && (ipt[midl][j]==ipt[midr][j] || ipt[midl][j]+1==ipt[midr][j])) || ipt[midl][j]=='Z') 
							ans.push_back(ipt[midl][j]);
						else break;
					if(j==ipt[midl].length()) cout << "case2.1: " << ans << endl;
					else if(j==ipt[midl].length()-1 && j>=ipt[midr].length()) { cout << "case2.2: " << ans << ipt[midl][j] << endl;}
					else { ans.push_back(char(ipt[midl][j]+1)); cout << "case2.3: " << ipt[midl][j+1] << "'s next added.  " << ans << " " << j << endl; }
				}
				else {
					cout << "case3: ";
					for(int j=0; j<i; j++) cout << ipt[midl][j];
					cout << char(ipt[midl][i]+1) << endl; 
				}
				ok=true;
				break;
			}
		}
		if(!ok) cout << ipt[midl] << endl;
			// for(int i=0; i<ipt[midl].length()-1; i++) cout << ipt[midl][i];
			// cout << char(*(--ipt[midl].end()) + 1) << endl;
		// }
	}
	return 0;
}