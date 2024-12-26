#include <iostream>
#include <cmath>
using namespace std;
int ln, rn, x, y;
int sz[10];
bool NBR=true;
int getLen(int num) {
	return log10(num)+1;
}//��ȡ����λ��
bool isp(int num) {
	if (num < 2) return false;
	if (num == 2)return true;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}//�ж�����
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
//void go(int x, int k) {  //k����λ����x��Ŀǰö�ٵ���λ��
//	if (x == (k + 1) / 2) {  //(k+1)/2��kλ���м����������Լ���һ��
//		for (int i = k; i > x; i--) {  //��ʣ�µ�λ������
//			a[i] = a[k - i + 1];
//		}
//		int shu = 0;  //������ת������
//		for (int i = 1; i <= k; i++) {
//			shu = shu * 10 + a[i];
//		}
//		if (shu < l)return; //С��l������
//		if (shu > r) { //����r������
//			NBR = false;
//			return;
//		}
//		if (isp(shu))cout << shu << endl; //�����������
//	}
//	else {
//		int i;
//		if (x)i = 0;
//		else i = 1; //���λ������0
//		for (i = i; i <= 9; i++) { //dfs(�����������)��һλ��ûѧ������ȥ����P1706
//			if (NBR == false)return; //����Ѿ����ִ���r����������������
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