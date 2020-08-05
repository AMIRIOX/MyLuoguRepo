#include <iostream>
using namespace std;
//int en[1020]={6};
int on[10]={6,2,5,5,4,5,6,3,7,6}; 
int matches(int num){
	if(num==0)return 6;
	int n=0;
	while(num!=0){
		n+=on[num%10];
		num /= 10;
	}
	return n;
}
int main(){
	int zs =0;
	cin >> zs;
	int res=0;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			if(matches(i)+matches(j)+matches(i+j)+4==zs) res++;
		}
	}
	cout << res;
	return 0;
}
