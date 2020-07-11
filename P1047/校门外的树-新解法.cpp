#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int trees[10001];
int L = 0;
int M = 0;
int Y = 0;
int area[100];

int main(){
	cin >> L; L++;
	cin >> M;
	
	//input nums;
	for(int i=0; i<(M*2); i++){
		cin >> area[i];
	}
	memset(trees,0,L);
	
	for(int i=0;i<(M*2);i+=2){
		for(int j=area[i]; j<=area[i+1]; j++){
			trees[j] = 1;
		}
	}
	
	int ans = L;
	for(int i=0;i<L;i++){
		if(trees[i]!=0)
			ans--;
	}
	
	cout << ans;
	return 0;
}
