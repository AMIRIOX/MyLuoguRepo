#include <iostream>
#include <set>
using namespace std;
/**************************************************
@brief   :
@author  : AMIRIOXŸoêÔ
@input   £º
@output  £º
@time    :
**************************************************/
int main() {
	set<int> a;
	int tmp;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (!a.count(tmp)) a.insert(tmp);
	}
	int i = 0;
	if (a.size() < k) {
		cout << "NO RESULT";
		return 0;
	}
		
	for (auto iv = a.begin(); iv != a.end(); iv++) {
		i++;
		if (i == k) {
			cout << *iv;
			break;
		} 
	}
	return 0;
}