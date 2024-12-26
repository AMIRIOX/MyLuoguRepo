#include <iostream>
using namespace std;
int main(){
	int ad[15];
	int hd = 0;
	int Count = 0;
	
	for(int i=1;i<=10;i++){
		cin >> ad[i];
	}
	cin >> hd;
	
	for(int i=1;i<=10;i++){
		if(ad[i] <= hd){
			Count++;
		}else if(ad[i]-30 <= hd){
			Count++;
		}
	}
	
	cout << Count;
	return 0;
}
