#include <iostream>
#include <string>
using namespace std;
const int os = 64;

int getNum(string& str){
	const int index =str.size();
	int a[index];
	int result = 1;
	for(int i=0;i<index;i++){
		a[i] = (int)str[i] - os;
		
	}
	for(int i=0;i<index;i++){
		result *= a[i];
	}
	
	//cout <<endl<< result;
	return result;
}
int main(){
	string HX;
	string XZ;
	cin >> HX >> XZ;
	
	int Hindex;
	int Xindex;
	
	//cout << Hindex <<" "<< Xindex;
	
	Hindex = getNum(HX) % 47;
	Xindex = getNum(XZ) % 47;
	
	if(Hindex == Xindex) cout << "GO";
	else cout << "STAY";

	return 0;
}
