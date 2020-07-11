//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <cctype>
//using namespace std;
////6a-5+1=2-2a     ->     a=0.750
//int string_int(string a) {
//	istringstream iss(a);
//	int i = 0;
//	iss >> i;
//	return i;
//}
//char xpos(string o) {
//	bool flg = false;
//	for (int i = 0; i < o.length(); i++) {
//		if (i == o.length() - 1 && flg == false) {
//			return '$';
//		}
//		else {
//			if(isalpha(o[i]))
//				return o[i];
//		}
//	}
//}
//int main() {
//	//输入方程
//	string ycfc;
//	cin >> ycfc;
//
//	//将方程为各位左右两部分
//	int pos = ycfc.find('=');//不会找不到=的,所以用int,如果找不到,那就是洛谷测试数据抽风
//	string h = ycfc.substr(pos + 1);  //方程右侧,之所以先算右侧是因为左侧要用到右侧的位置
//	string q = ycfc.substr(0,ycfc.length()-h.length()-1);  //方程左侧,总长度=右侧长度-1就是前面长度
//
//	//输出测试
//	/*cout <<"原方程: "<< ycfc << endl;
//	cout << "前: " << q << endl;
//	cout << "后: " << h << endl;*/
//
//	//获取未知数
//	char qwzs = xpos(q);
//	char wzs = qwzs == '$' ? xpos(h) : qwzs;
//	cout << wzs;
//
//	//把h中带有未知数的项(如果有)插入到q中第一个带有未知数的项的字母后面,并把原位置改为'$'.
//	//草,我特么直接把右面移到左面得了
//	//?那他妈我分离左右干啥?
//	//草.!@#$%#!$!%&&^*$#%(*)^#!@$#%_$%$#%@^%$&%$%!$*&^$^^%(*)($@#!$$^%^@&#*#@%@#*%!%#*&
//	/*string::size_type fxp = q.find(wzs)+1;
//	for (int i = 0; i < h.length(); i++) {
//		if (h[i] == wzs) {
//			int p = -1;
//			for (int j = i; j >= 0; j--) {
//				if (!isalnum(h[j])) {
//					p = j;
//					break;
//				}
//			}
//			if (p == -1) p=0;
//			string tmp2 = h.substr(p).substr(0,i+1);
//			q.insert(fxp,tmp2);
//			
//		}
//	}*/
//	cout << q;
//	return 0;
//}