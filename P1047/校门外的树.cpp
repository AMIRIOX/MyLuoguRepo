#include <iostream>
#include <vector>
using namespace std;
int main(){
	int L = 0;
	cin >> L; L++; //0~L有 L+1个数 
	
	int M = 0;
	cin >> M;
	
	vector<int> area;  
	int tmp;
	
	for(int i=0; i<(M*2); i++){
		cin >> tmp;
		area.push_back(tmp);
	}
	
	//处理树木的移动 
	for(int i=1; i<=(M*2); i+=2){
		
		if(i != 1){
			for(int j=i-2; j>=0; j-=2){
				if(area[i-1]>area[j] || area[i]<area[j-1]){
					tmp = area[i]-area[i-1]+1;
					L -= tmp; 
				}else if(area[i-1]==area[j-1] && area[i]==area[j]){
					continue;
				}else if(area[i-1]==area[j-1]){
					tmp = area[i]-area[j];
					L -= tmp;
				}else if(area[i]==area[j]){
					tmp = area[i-1]-area[j-1];
					L -= tmp;
				}
				
				else{
					continue;
				}
			}
		}
		


	}
	
	
	cout <<L;
	return 0;
}
