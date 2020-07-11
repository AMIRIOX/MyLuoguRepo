#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1000;
double f[maxn];
int main(){
	int n;
	cin >> n;
	f[0]=0;
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	printf("%0.2lf",f[n]);
}
