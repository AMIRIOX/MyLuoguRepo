#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=2e6+10;
//题意:给定一个分数0/x，每次进行如下两个操作之一
// 1. 如果能约分就约分
// 2. 否则分子加一

//思路：
// 对于一个0/x,如果x是素数答案就直接是x，如果不是就找到最小的约数
int tag[maxn];
int gcd(int x, int y) {
	return y?gcd(y,x%y):x;
}
void eratho() {
	for(int i=2;i*i<=maxn;i++) {
		if(!tag[i]) {
			for(int j=i+i; j<maxn; j+=i) {
				tag[j]=1;
			}
		}
	}
}
bool isprime(int x) {
	return !tag[x];
}
int pv(int x) {
	while(!isprime(x)) x--;
	return x;
	// 1<=x<=n f(x)最大操作次数
	// 设距离n最近的左侧质数为p，则times(f(p))=p;
	// 在[1,p)范围内的某个xi，若xi为质数，则times(f(xi))=xi<p
	// 若xi为合数，则将会分子自增g1次，约分g2次得到一个质数xj，
	// 易得(?) times(f(xj))+g1+g2=xj<=p
	// 在(p,n]范围内的某个xi，不可能为质数（p是距离n最近的质数）
	// xi为合数，设xi自增g1，约分g2次得到一个质数

	// 推导
	// 1[         ]质数p[         ]合数xi=2p  n
	// 若xi>=2*p,则xi/2>=p，次数比p多
	// 若xi<2*p，则次数比p少

	// 推广
	// 若xi>=h*p，则x/h>=p，那么times(f(xi))就不断约分xi逼近p，设为d
	// 然后答案就是逼近过程中的次数再加上剩下的1~d。


	// 想不出来了 上述作废 重想

	//复杂度角度分析：T最大5e5，n最大2e6，按照ccf少爷机1e9/s，平均每个n也就1e4次运算
	// O(n)肯定是超了，大概是O(sqrt(n))的水平，log的话有点离谱
	// 根号n的明显是素数筛，但是想不到什么好的方法，想要复杂度是根号n，
	// 要么是裸素数筛要么是后续加入的代码复杂度不超过根号n
	// 什么玩意复杂度能不写过根号n啊啊啊啊啊啊啊啊啊啊啊啊

	// 哦对，大概可以预处理出来然后一起输出，只要T个n总体运算次数不超过1e9即可
	// 那我彻底没思路了

	// 看完讨论区大佬，这他妈是黄题？（然而还是不会）
	// 有人说和noip T1有点像，大概指的是去年的NOIP，我去看看P7960
	// 没 有 算 法 标 签，好家伙
	// 嗯，确实也是筛素数的题，然而还是不会P8319

	// 看完P7960复杂度分析，我觉得我这辈子也碰不上提高组的门槛了
	// 算了 回家写作业。

	// day3: 思路清晰些了。前些天猜的结论是n之前的第一个素数。
	// 交了一发还真过了，昨晚试着证了下，总觉得不完美
	// 待会回家问问大佬
}

int main() {
	eratho();
	int T;
	cin >> T;
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", pv(n));
	}
	return 0;
}