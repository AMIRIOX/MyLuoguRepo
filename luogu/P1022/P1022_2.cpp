#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
int n[120];      //ÿһλ����
int cur=1, zf;  //��ǰλ�õ�����.ϵ��   ������
char c,x;      //��ȡ���ַ�  δ֪��
int num;      //����֮��
int xs;      //ϵ��֮��
int eq;     //�Ⱥ�λ��
int main() {
	zf = 1;
	memset(n,0,sizeof(n));
	while (c != '=') {
		c = getchar();
		if (c == '-') 
			zf = -1, cur++;
		if (c == '+') 
			zf = 1,cur++;		
		if (c >= 'a' && c <= 'z') {
			x = c;
			if (n[cur] == 0)
				xs += zf;
			else
				xs += n[cur],n[cur] = 0;
			cur--;
		}
		else if (c >= '0' && c <= '9')
			n[cur] = n[cur] * 10 + (c - '0')*zf;
	}
	eq = cur; cur++; zf = 1;
	while (c != '\n') {
		c = getchar();
		if (c == '-') 
			zf = -1, cur++;
		if (c == '+') 
			zf = 1, cur++;
		if (c >= 'a' && c <= 'z') {
			x = c;
			if (n[cur] == 0)
				xs -= zf;
			else
				xs -= n[cur], n[cur] = 0;
			cur--;
		}
		else if (c >= '0' && c <= '9')
			n[cur] = n[cur] * 10 + (c - '0') * zf;
	}

	for (int i = 1; i <= cur; i++) {
		if (i <= eq) 
			num -= n[i];
		else 
			num += n[i];
	}
	cout.setf(ios::fixed);
	cout << x << "=";
	if (((double)num / (double)xs) == -0) {
		cout << fixed << setprecision(3) << "0.000";
	}
	else {
		cout << fixed << setprecision(3) << ((double)num / (double)xs);
	}
	
	return 0;
}