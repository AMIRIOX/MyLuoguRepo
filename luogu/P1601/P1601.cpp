//#include <iostream>
//#include <string>
//#include <cstring>
//
///**************************************************
//@brief   :
//@author  : AMIRIOXŸoêÔ
//@input   £º
//@output  £º
//@time    :
//**************************************************/
//
//using namespace std;
//int a[250];
//int b[250];
//int main() {
//	string num;
//	string num2;
//	cin >> num >> num2;
//
//	memset(a, 0, sizeof(a));
//	memset(b, 0, sizeof(b));
//
//	a[0] = num.length();
//	b[0] = num2.length();
//
//	for (int i = 1; i <= a[0]; i++) {
//		a[i] = num[a[0] - i] - '0';
//	}
//	for (int i = 1; i <= b[0]; i++) {
//		b[i] = num2[b[0] - i] - '0';
//	}
//	int leng = (a[0] > b[0] ? a[0] : b[0]);
//	for (int i = 1; i <= leng; i++) {
//		a[i] += b[i];
//		a[i + 1] += a[i] / 10;
//		a[i] %= 10;
//	}
//
//	leng++;
//	while ((a[leng] == 0) && (leng > 1)) leng--;
//	for (int i = leng; i >= 1; i--) {
//		cout << a[i];
//	}
//	
//	return 0;
//}
//
