#include <iostream>
#include <string>
using namespace std;
char bc(char a){
	char ret;
	
	if(a=='z'){
		ret = 'a';
		return ret;
	}
	ret = a+1;
	
	return ret;
}
int main(){
	int n;
	string rpw;
	cin >> n >> rpw;
	
	for(int i=0;i<rpw.size();i++){
		for(int j=1;j<=n;j++){
			rpw[i] = bc(rpw[i]);
		}
		//cout <<rpw<<endl;
	}
	
	cout << rpw;
	
	return 0;
}
