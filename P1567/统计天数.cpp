#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<int> maxTmp;
int Count=0;
int tmp;
int result = 0;

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> tmp;
		maxTmp.push_back(tmp);
	}
	
	for(int i=1;i<=N;i++){
		if(maxTmp[i]>maxTmp[i-1]){
			Count++;
		}else{
			Count = 1;
		}
		if(Count>result) result = Count;
		cout << "Day "<<i<<":count="<<Count<<",Result="<<result<<endl;
	}
	
	//cout << Count; 
	return 0;
}
