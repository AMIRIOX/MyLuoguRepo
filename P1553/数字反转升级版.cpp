#include <iostream>
#include <string>
#include <vector>
#include <cctype> 
using namespace std;
void kilD(vector<char>& a){//删掉后面的0 
	if(a.size()==1 || a[0]=='0') return;
	//cout << a.back()<<endl;
	while(a.back()=='0'){
		a.pop_back();
	}
}
void kilX(vector<char>& a){//删掉前面的0 
	if(a.size()==1) return;
	for(int i=0;i<a.size();i++){
		if(a[i]!='0') break;
		//delete the first element of a;
		if(a[i]=='0'){
			//cout << "=========" << endl;
			i--;
			vector<char>::iterator k = a.begin();
			a.erase(k);
		}
	}
}

int main(){
	//temp variable
	int index=0;
	vector<char> tmp;
	bool flag = false;
	vector<char> tmp2;
	char what;
	
	//input
	string num;
	cin>>num;
	
	if(num.size()==1 && num[0]=='0'){
		cout <<"0";
		return 0;
	}

	
	//output (test)
	//cout <<num<<"vvv";
	
	//process
	for(int i=0;i<num.size();i++){
		if(num[i]!='.' && num[i]!='%' && num[i]!='/' && !flag){
			tmp.push_back(num[i]);
		}
		if(num[i]=='.' || num[i]=='%' || num[i]=='/'){
			what = num[i];
			flag=true;
			continue;
		}
		if(flag){
			tmp2.push_back(num[i]);
		}
	}
	if(what=='%'){
		kilD(tmp);
		for(int i=tmp.size()-1;i>=0;i--){
			cout << tmp[i];
		}
		cout << what;
		return 0;
	}
	if(!flag){
		kilD(tmp);
		for(int i=tmp.size()-1;i>=0;i--){
			cout << tmp[i];
		}
		
		//如果AC不过,就考虑正常整数的0小布消除 
		//果然就是整数后面0的事... 
	}else{//cout << "-=-=-";
		kilD(tmp);
		kilD(tmp2);
		
		kilX(tmp2);
		
		kilD(tmp); 
		for(int i=tmp.size()-1;i>=0;i--){
			cout << tmp[i];
		}
		cout << what;
		kilX(tmp2);
		for(int i=tmp2.size()-1;i>=0;i--){
			cout << tmp2[i];
		}
	}
	return 0;
} 

