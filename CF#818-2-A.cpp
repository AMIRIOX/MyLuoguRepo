#include <iostream>
#include <cstdio>
using namespace std;
/*
最小公倍数 除以 最大公约数 <3

质因数分解（只因数分解(大雾)），

最大公约数3

2*4*4=32

4*4*5=80

1,1   *2*2*2*2...(<n)  *3*3*3*3*3...(<n)
1,2   
1,3

a最多乘n/2个2，n/3个3，n/4个4，i.e., n/x个x，对于每个xi都有n/x种a的取值，一共(n/a)*(n/x)种
b同理
但要求a<=b 对于每个(b, xi, k)=b*(xi^k)的取值，a只能取你妈的



int gcd(int x, int y) {
	return y?gcd(y%x, x):x;
}

int lcm(int x, int y) {
	return x/gcd(x,y)*y;
}

lcm/gcd= x*y/gcd/gcd

1~n之间 x/gcd * y/gcd <=3  的对数

看清题目，没说a<b。 从宏观角度考虑，不要掉入模拟巨坑
(1,1)为基底乘上一堆相同数字，不就是(x,x)
所以(x,x) (x,2x) (x,3x)符合要求
答案为n+floor(n/2)*2+floor(n/3)*2

*/
int t;

signed main() {
	cin >> t;
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", n+n/2*2+n/3*2);
	}
	return 0;
}