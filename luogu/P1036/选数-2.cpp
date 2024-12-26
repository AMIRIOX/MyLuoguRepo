#include <iostream>
using namespace std;


typedef long long LL; 
LL res = 0;
int nums[200];
int n=0,k=0;
bool isp(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
//三个参数:
//int stop = 终止条件,当stop==k时递归终止
//int sum = 几个数累加的和
//int up = 不降原则去重
void dfs(int stop,int sum,int up){
	
    if(stop==k){
    	if(isp(sum)) res++;
    	return ;
	}
	
	for(int i=up;i<n;i++){
    	dfs(stop+1,sum+nums[i],i+1);
	}
        
}
int main(){

    cin >> n >> k;
    for(int i=0;i<n;i++){
    	cin >> nums[i];
	}
	dfs(0,0,0);
	cout << res;
    return 0;
}
