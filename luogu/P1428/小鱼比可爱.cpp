#include <iostream>
using namespace std;
/*
    ��֪n������fish[n],�����ÿ������fish[i]
	����ж�����ֵ���Լ�С�� 
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
