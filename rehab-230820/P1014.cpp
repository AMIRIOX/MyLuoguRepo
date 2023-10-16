#include <iostream>
#include <cstdio>
using namespace std;
int n, c, sn;
signed main(int argc, char const *argv[]){
	cin >> n;
	while(sn<n) sn+=(++c);
	int f=c-(n-c*(c-1)/2)+1;
	if(c%2!=0) f=c-f+1;
	printf("%d/%d", c+1-f, f);
	return 0;
}