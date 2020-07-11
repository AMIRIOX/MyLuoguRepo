#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n,k;	
int x[5000020];  //n个数字 
vector<int> ans;   //和的集合 
vector<int> tn[3]={-1,-1,-1};    //k个数往里填 
/*void dfs(int cur){//cur is a index of nums[cur].s
	if(cur==k){
		int tmp = 0;
		for(int i=0;i<k;i++){
			//tmp += tn[i];
			cout << tn[i];
		}
		ans.push_back(tmp);
		memset(tn,-1,3);
		cout <<endl<<cur<<" "<<ans.back()<<endl;
	}else for(int i=0;i<n;i++){		
		cout <<endl<<cur<< ":Not enough.push "<<x[i]<<" to bit:"<<cur<<endl;
		for(int j=0;j<)
		if(cur!=0 && x[i]==tn[cur-1]) continue;
		tn[cur]=x[i];
		dfs(cur+1);
	}
}*/
void dfs(){
	
}
int main(){
	int tmp=0;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	dfs(0);
	for(int i=0;i<ans.size();i++) {
		cout << ans[i] <<" ";
	}
	
	
	
	return 0;
} 
