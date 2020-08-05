#include <stdc++.h>
using namespace std;
int a[250];
int b[250];
string num;
string num2;
int cmp(string a, string b) {

	if (a.length() > b.length()) return 1;
	else if (a.length() < b.length()) return -1;
	else {
		for (int i = 1; i < a.length(); i++) {
			if (a[i] > b[i]) return 1;
			if (a[i] < b[i]) return -1;
		}
		return 0;
	}

}
int cmp(int* a, int* b) {
	if (a[0] > b[0])
		return 1;
	if (a[0] < b[0])
		return -1;
	for (int i = a[0]; i > 0; i--) {
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
	}
	return 0;
}
void sub(int *a, int *b) {
	int flg = cmp(a,b);
	if (flg == 0) {
		a[0] = 0;
		return ;
	}
	if (flg == 1) {
		for (int i = 1; i <= a[0]; i++) {
			if (a[i] < b[i]) {
				a[i + 1]--;
				a[i] += 10;
			}
			a[i] -= b[i];
		}
		while (a[0] > 1 && a[a[0]] == 0)
			a[0]--;
		return ;
	}
}
int main() {
	cin >> num >> num2;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	
	//加法
	a[0] = num.length();
	b[0] = num2.length();

	for (int i = 1; i <= a[0]; i++) {
		a[i] = num[a[0] - i] - '0';
	}
	for (int i = 1; i <= b[0]; i++) {
		b[i] = num2[b[0] - i] - '0';
	}
	int leng = (a[0] > b[0] ? a[0] : b[0]);
	for (int i = 1; i <= leng; i++) {
		a[i] += b[i];
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}

	leng++;
	while ((a[leng] == 0) && (leng > 1)) leng--;
	for (int i = a[0]; i >= 1; i--) {
		cout << a[i];
	}
	cout << endl;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	//减法
	a[0] = num.length();
	b[0] = num2.length();
	for (int i = 1; i <= a[0]; i++) {
		a[i] = num[a[0] - i] - '0';
	}
	for (int i = 1; i <= b[0]; i++) {
		b[i] = num2[b[0] - i] - '0';
	}
	int flg = cmp(num, num2);
	if (flg == 0) cout << 0 << endl;
	else if (flg == 1) {
		for (int i = 1; i <= a[0]; i++) {
			a[i] -= b[i];
			if (a[i] < 0) {
				a[i + 1]--;
				a[i] += 10;
			}
		}
		a[0]++;
		while (a[a[0]] == 0 && a[0] > 1) a[0]--;
		for (int i = a[0]; i > 0; i--) {
			cout << a[i];
		}
		cout << endl;
	}
	else if (flg == -1) {
		cout << '-';
		for (int i = 1; i <= b[0]; i++) {
			b[i] -= a[i];
			if (b[i] < 0) {
				b[i + 1]--;
				b[i] += 10;
			}
		}
		b[0]++;
		while (b[b[0]] == 0 && b[0] > 1) b[0]--;
		for (int i = b[0]; i > 0; i--) {
			cout << b[i];
		}
		cout << endl;
	}
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	//乘法
	int c[250];
	a[0] = num.length();
	b[0] = num2.length();
	for (int i = 1; i <= a[0]; i++) {
		a[i] = num[a[0] - i] - '0';
	}
	for (int i = 1; i <= b[0]; i++) {
		b[i] = num2[b[0] - i] - '0';
	}
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= a[0]; i++) {
		for (int j = 1; j <= b[0]; j++) {
			c[i + j - 1] += a[i] * b[j];
			c[i + j] += c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
	}
	int len = a[0] + b[0] + 1;

	while ((c[len] == 0) && (len > 1)) len--;
	for (int i = len; i >= 1; i--) {
		cout << c[i];
	}
	cout << endl;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	//除法
	a[0] = num.length();
	b[0] = num2.length();
	for (int i = 1; i <= a[0]; i++) {
		a[i] = num[a[0] - i] - '0';
	}
	for (int i = 1; i <= b[0]; i++) {
		b[i] = num2[b[0] - i] - '0';
	}
	c[0] = a[0] - b[0] + 1;
	int tmp[250];
	for (int i = c[0]; i >= 1; i--) {
		memset(tmp, 0, sizeof(tmp));
		for (int j = 1; j <= b[0]; j++) {
			tmp[j + i - 1] = b[j];
		}
		tmp[0] = b[0] + i - 1;
		while (cmp(a, tmp) >= 0) {
			c[i]++;
			sub(a, tmp);
		}
	}
	while (c[0] > 1 && c[c[0]] == 0)c[0]--;
	for (int i = c[0]; i >= 1; i--) {
		cout << c[i];
	}
	cout << endl;
	if (a[0] == 0) {
		cout << 0;
		return 0;
	}
	while (a[0] > 1 && a[a[0]] == 0)a[0]--;
	for (int i = a[0]; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}