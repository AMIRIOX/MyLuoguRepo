#include <iostream>
using namespace std;
int evn[2020]={6};
int ovn[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	int res=0;
	int n=0;
	cin >> n;
	for(int i=1;i<=2000;i++){
		int tmp=i;
		while(tmp!=0){
			evn[i] = evn[i]+ovn[tmp%10];
			tmp /= 10; 
		}
	}
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			if(evn[i]+evn[j]+evn[i+j]+4==n)res++;
		}
		cout << " wdnmd ";
	}
	cout << res;
	return 0;
} 
