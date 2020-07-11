int getSec(int n){
	int cnt;
	while(1){
		if(n<100) break;
		n /= 10;
	}
	cnt = n%10;
}
using namespace std;
#include <iostream>
int main(){
	int n;
	cin>>n;
	cout << getSec(n);
	return 0;
}
