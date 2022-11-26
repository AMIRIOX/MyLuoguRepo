#include <iostream>
#include <cstdio>
// 给定字符串A，B，将G和B视为一个字符，判断AB是否相同
using namespace std;
int t, l;
int main() {
	cin >> t;
	while(t--) {
		scanf("%d", &l);
		string A,B;
		cin >> A >> B;
		bool ok=true;
		for(int i=0;i<l;i++) {
			if(A[i]==B[i] || (A[i]=='B'&&B[i]=='G') || A[i]=='G'&&B[i]=='B') ;
			else { ok=false; break; }
		}
		printf("%s\n", ok?"YES":"NO");
	}
	return 0;
}