#include <iostream>
#include <string>
using namespace std;
int main(){
	string isbn;
	cin >> isbn; 
	
	//��ȡ���������� 
	int numIndex = 0;
	int nums[10];
	for(int i=0; i<13; i++){
		if(isbn[i] != '-'){
			if(isbn[i]=='X'){
				nums[numIndex++]=10;
			}else{
				nums[numIndex++]=isbn[i]-'0';
			}
			//cout << nums[numIndex-1]<< " " << tmp << endl;
		} 
	}
	
	//��ʼ����
	int right = 0;
	for(int i=0; i<9; i++){//�������һ����ʶ�� 
		right += nums[i]*(i+1);
	} 
	right = right%11;
	if(nums[9]==right) cout<<"Right";
	else{
		for(int i=0;i<12;i++){
			cout << isbn[i];
		}
		if(right == 10) cout << 'X';
		else cout << right;
	}
	
	
	return 0;
}
