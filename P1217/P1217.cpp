#include <iostream>
#include <cmath>
using namespace std;
int ln, rn, x, y;
int sz[10];
bool NBR=true;
int getLen(int num) {
	return log10(num)+1;
}//获取整数位数
bool isp(int num) {
	if (num < 2) return false;
	if (num == 2)return true;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}//判断质数
void dfs(int x, int k) {
	if (x == (k + 1) / 2) {
		for (int i = k; i > x; i--) {
			sz[i] = sz[k - i + 1];
		}
		int shuzi = 0;
		for (int i = 1; i <= k; i++) {
			shuzi = shuzi * 10 + sz[i];
		}
		if (shuzi < ln) return;
		if (shuzi > rn) {
			NBR = false;
			return;
		}
		if (isp(shuzi))cout << shuzi << endl;
	}
	else{
		int a;
		if (x == 0) a = 1;
		else a = 0;
		for (int i = a; i <= 9; i++) {
			if (NBR == false) return;
			sz[x + 1] = i;
			dfs(x + 1, k);
		}
	}
}
//void go(int x, int k) {  //k是总位数，x是目前枚举到的位置
//	if (x == (k + 1) / 2) {  //(k+1)/2是k位的中间数，可以自己算一下
//		for (int i = k; i > x; i--) {  //把剩下的位数完善
//			a[i] = a[k - i + 1];
//		}
//		int shu = 0;  //将数组转化成数
//		for (int i = 1; i <= k; i++) {
//			shu = shu * 10 + a[i];
//		}
//		if (shu < l)return; //小于l就跳过
//		if (shu > r) { //大于r就跳出
//			NBR = false;
//			return;
//		}
//		if (isp(shu))cout << shu << endl; //是质数就输出
//	}
//	else {
//		int i;
//		if (x)i = 0;
//		else i = 1; //最高位不能是0
//		for (i = i; i <= 9; i++) { //dfs(深度优先搜索)下一位，没学过可以去看下P1706
//			if (NBR == false)return; //如果已经出现大于r的数，就跳出函数
//			a[x + 1] = i;
//			go(x + 1, k);
//		}
//		return;
//	}
//	
//	

int main() {
	cin >> ln >> rn;
	x = getLen(ln);
	y = getLen(rn);
	for (int i=x;i<=y;i++) {
		if (i == 1) {
			if (ln <= 5 && rn >= 5) cout << 5 << endl;
			if (ln <= 7 && rn >= 7) cout << 7 << endl;
			continue;
		}
		if (i == 2) {
			if (ln <= 11 && rn >= 11) cout << 11 << endl;
			continue;
		}
		if (i % 2 == 0) continue;
		if (i == 9) break;
		NBR = true;
		dfs(0, i);
	}
	return 0;
}