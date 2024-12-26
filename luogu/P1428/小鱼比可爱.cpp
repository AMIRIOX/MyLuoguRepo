#include <iostream>
using namespace std;
/*
    已知n个整数fish[n],求对于每个整数fish[i]
	左边有多少数值比自己小的 
*/
int fish[110];
int main(){
	
	//input
	int n;
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> fish[i];
	}
	
	for(int i=0;i<n;i++){
		int Count = 0;
		for(int j=i-1; j>=0; j--){
			if(fish[i]>fish[j]){
				Count++;
			}
		}
		cout << Count;
		if(i!=n-1) cout << " ";
	}
	 
	return 0;
}
