#include <iostream>
#include <cmath>
using namespace std;
int cnt=1;
int zero=0;
int getBit(int number){
	int qcnt=0;
	while(number!=0){
		number/=10;
		qcnt++;
	}
	return qcnt;
}
int getSec(int n){
	int cnt;
	while(1){
		if(n<100) break;
		n /= 10;
	}
	cnt = n%10;
}
int getZero(int num){
	if(num==0||num<=9) return 10;
	int bcnt=getBit(num);
	//100 Ó¦·µ»Ø10^3
	return pow(10,bcnt);
}
void addNum(int num){
	int a=1;
	zero=getZero(num);
	int f=getSec(num);
	//while((f==0 && (f/2)!=0) || a<=(num/f)/2){
	while(a+1 <= f/2){
		cnt++;
		int last = num;
		num =a*zero+num;
		int bcs=pow(10,getBit(num)-1);
		cout << num <<" "<<(num/bcs)/2<<endl;
		if(((num/bcs)/2)>0)
			addNum(num);     //10^(bit-1) 
		f=getSec(num);
		cout << endl << "/2=" << f<<endl;
		//6
		//16 0
		//1
	}
}
int main(){
	int num=0;
	cin>>num;
	addNum(num);
	cout << cnt;
}
