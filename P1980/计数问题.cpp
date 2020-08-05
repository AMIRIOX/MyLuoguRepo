#include <iostream>
#include <string>
using namespace std;
int getBit(int nums){
	int Count = 0;
	if(nums == 0) return Count;
	while(nums > 0){
		nums /= 10;
		Count++;
	}
	return Count;
}
int main(){
	int result = 0;
	int n,x;
	cin>>n>>x;
	
	for(int i=1;i<=n;i++){
		int cot = getBit(i);
		string tmp = to_string(i);
		string x_s = to_string(x);
		for(int i=0;i<cot;i++){
			if(tmp[i] == x_s[0])
				result++;
		}
	}
	
	cout << result;
	return 0;
} 
