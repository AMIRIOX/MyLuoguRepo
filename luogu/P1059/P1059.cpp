//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n[120];
//int t[120];
//void Swap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = a;
//}
//int main() {
//    int N;
//    cin >> N;
//    memset(t, 0, sizeof(t));
//    for (int i = 0; i < N; i++) {
//        cin >> n[i];
//    }
//    int p = 0;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N-i-1; j++) {
//            if (n[j] > n[j+1]) {
//                swap(n[j], n[j + 1]);
//            }
//            if (n[j] == n[j + 1] && t[n[j+1]]!=1) {
//                t[n[j+1]] = 1;
//            }
//        }     
//    }
//    for (int j = 0; j < N; j++) {
//        /*if (t[j] != 1) {
//            p++;
//        }*/
//        cout << t[j] << " ";
//    }cout << endl;
//    cout << p << endl;
//    for (int i = 0; i < N; i++) {
//        if(t[n[i]]!=1)
//            cout << n[i] <<" ";
//    }
//    return 0;
//}
#include <set>
#include <iostream>
using namespace std;
int main() {
	set<int> a;
	int N,tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (!a.count(tmp)) a.insert(tmp);
	}
	cout << a.size() << endl;
	for (auto iv = a.begin(); iv != a.end(); iv++) {
		cout << *iv << " ";
	}
}