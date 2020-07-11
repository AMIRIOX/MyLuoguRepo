#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<char> res;

char tp(string a){
	bool isA=1;
	bool isB=1;
	if(a.size()==1){
		if(a[0]=='0') isB=0;
		else isA=0;
	}
	
	
	for(char i=0;i<a.size();i++){
		if(a[i]=='1') isA=0;
	}
	for(char i=0;i<a.size();i++){
		if(a[i]=='0') isB=0;
	}
	if(isA) return 'A';
	if(isB) return 'B';

	return 'F';
}
void lifecode(string kty){
	char state = tp(kty);
	//cout <<kty<<" and " <<state<<endl;
	if(state=='A' || state=='B' || (kty.size()==1 && (kty[0]=='0' || kty[0]=='1')) ){
		res.push_back(state);
		//printf("if %c\n",state);
		return ;
	} 
	else{
		//cout << kty << endl;
		res.push_back('C');
		string before = kty.substr(0,kty.size()/2);
		string behind = kty.substr(kty.size()/2,kty.size()/2);
		lifecode(before);//前半部分字符串 
		lifecode(behind);//后半部分字符串
	}
}
int main(){
	//freopen("out.out","w",stdout);
	string str;
	cin >> str;
	lifecode(str);
	for(int i=0;i<res.size();i++)
		printf("%c",res[i]);
	return 0;
} 
