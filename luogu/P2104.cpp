#include <iostream>
#include <cstdio>
using namespace std;
const int manx=5e6+10;
int f[manx*2],n,m;
int l,r;
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> m;
	l=1; r=n;
	char x;
	for(int i=1;i<=n;i++) {
		// scanf("%1d", &f[i]);
		cin >> x; f[i]=x-'0';
	}
	for(int i=1;i<=m;i++) {
		char x;
		// scanf("%1c", &x);
		cin >> x;
		if(x=='+') f[r]++;
		if(x=='-') f[r]--;
		if(x=='/') f[r-1]+=f[r]>>1, r--; //+=! :不能舍弃自己
		if(x=='*') f[++r]=0;
	}
	for(int i=r;i>1;i--) {
		f[i-1]+=f[i]>>1; //二进制近卫 +=! :不能舍弃自己
		f[i]=f[i]&1;    //去掉进位的剩余数字(最后一位数字)
	}
	for(int i=1;i<=r;i++) {
		printf("%d", f[i]);
	}
	puts("");
	return 0;
}