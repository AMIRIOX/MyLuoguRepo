#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int xl[100010], cb;
inline int read(){
	int val=0, flg=1;
	char c=getchar();
	while(c<'0' || c>'9') {
		if(c=='-') flg=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') {
		val=(val<<1)+(val<<3)+(c^48);
		c=getchar();
	}
	return val*flg;
}
signed main() {
	int zf=read();
	int a, b;
	memset(xl, -1, sizeof(xl));
	cin >> a >> b;
	cb=a; xl[a]=b;
	int maxprice=-0x7fffffff, mpxl=-0x7ffffff;
	while((a=read())!=-1 && (b=read())!=-1) {
		xl[a]=b;
		if(a>maxprice) {
			maxprice=a;
			mpxl=b;
		}
	}
	b=read();

	//-------
		

	return 0;
}
