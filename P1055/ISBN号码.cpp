#include <iostream>
#include <string>
using namespace std;
int main(){
	string isbn;
	cin >> isbn; 
	
	//获取纯数字数组 
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
	
	//开始计算
	int right = 0;
	for(int i=0; i<9; i++){//不算最后一个标识符 
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
