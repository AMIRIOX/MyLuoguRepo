#include <iostream>
#include <cstdio>
// 1 gcd 返回a,b的最大公约数
int gcd(int a, int b) {
	return b ? a : gcd(b, a%b);
} // lcm同理可推

// 2 exgcd ax+by=gcd(a,b)
int gcd(int a, int b, int& x,int& y) {
	if(!b) {
		x=1; y=0;
	}else {
		gcd(b, a%b, y, x);
		y -= x*(a/b);
	}
}

// 3 eratosthenes
int isp[2000];
void era(int n) {
	for(int i=2; i*i<=n; i++) {
		if(!isp[i])
		for(int j=i*i; j<=n; j+=i) {
			isp[j]=1;
		}
	}
} // 素数定理： pi(x) ~ x/lnx

// 4 ax+by=c的解？
// 若ax+by=gcd(a, b)存在解x0, y0
// 当c是gcd(a, b)的倍数时：解为(x0*c/gcd(a,b), y0*c/gcd(a,b))
// 否则无解

// 5 不定方程ax+by=n若存在解x0, y0，则其他解为(x0+kb', y0-ka')
// 其中a'=a/gcd(a, b), b'=b/gcd(a,b)
// 记忆：多解一定有k，先加后减、ab错位

// 6 同余
// a \equiv b (mod n) 等价于 a-b是n的整数倍
// ax \equiv 1 (mod n) 的解（同余等价类）x叫做a的逆。当a与n互素时存在唯一的x

// 7 唯一分解定理的应用
// 8 欧拉函数

signed main() {

	return 0;
}