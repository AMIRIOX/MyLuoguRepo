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
//	//���뷽��
//	string ycfc;
//	cin >> ycfc;
//
//	//������Ϊ��λ����������
//	int pos = ycfc.find('=');//�����Ҳ���=��,������int,����Ҳ���,�Ǿ�����Ȳ������ݳ��
//	string h = ycfc.substr(pos + 1);  //�����Ҳ�,֮���������Ҳ�����Ϊ���Ҫ�õ��Ҳ��λ��
//	string q = ycfc.substr(0,ycfc.length()-h.length()-1);  //�������,�ܳ���=�Ҳ೤��-1����ǰ�泤��
//
//	//�������
//	/*cout <<"ԭ����: "<< ycfc << endl;
//	cout << "ǰ: " << q << endl;
//	cout << "��: " << h << endl;*/
//
//	//��ȡδ֪��
//	char qwzs = xpos(q);
//	char wzs = qwzs == '$' ? xpos(h) : qwzs;
//	cout << wzs;
//
//	//��h�д���δ֪������(�����)���뵽q�е�һ������δ֪���������ĸ����,����ԭλ�ø�Ϊ'$'.
//	//��,����ôֱ�Ӱ������Ƶ��������
//	//?�������ҷ������Ҹ�ɶ?
//	//��.!@#$%#!$!%&&^*$#%(*)^#!@$#%_$%$#%@^%$&%$%!$*&^$^^%(*)($@#!$$^%^@&#*#@%@#*%!%#*&
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