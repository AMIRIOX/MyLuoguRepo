#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
int cmped[100000];
int inNums[100000];
int main(){
	//varibles
	int n;
	int tmp;
	int Count = 0;	
	
	//input
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> tmp;
		inNums[tmp] = 1;
		nums.push_back(tmp);
	}

	tmp=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int num = nums[i]+nums[j];
			cmped[num] = 1;
			if(num>tmp) tmp = num;
		}
	}
 
	for(int i=0;i<tmp;i++){
		if(cmped[i] && inNums[i]) Count++;
	}
	
	
	cout << Count;
	return 0;
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			 
			
			int okNum = nums[j]-nums[i];
			if(okNum==nums[i] || okNum<0) continue;
			cout << okNum << " ";
			
			vector<int>::iterator iter=std::find(nums.begin(),nums.end(),okNum);//返回的是一个迭代器指针
        	if(iter!=nums.end()) cout << i << okNum << *iter << " ";


		}
	}*/
}
