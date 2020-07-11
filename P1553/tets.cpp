#include <iostream>
#include <vector>
using namespace std;
void kilX(vector<char>& a){
	if(a.size()==1) return;
	for(int i=0;i<a.size();i++){
		if(a[i]!='0') break;
		//delete the first element of a;
		if(a[i]=='0'){
			cout << "=========" << endl;
			vector<char>::iterator k = a.begin();
			a.erase(k);
			
		}
	}
}
//222090900
int main(){
	string a;
	vector<char> b;
	cin >> a;
	for(int i=0;i<a.size();i++){
		b.push_back(a[i]);
	}
	kilX(b);
	for(int i=0;i<b.size();i++){
		cout << b[i];
	}
	return 0;
}
