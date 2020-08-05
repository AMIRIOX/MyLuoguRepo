#include <iostream>
using namespace std;

int main(){
    int k = 0;
    cin >> k;
    //int n = 1;
    
    double Sr = 0;
    for(int i=1; Sr <= k+1; i++){
        Sr += 1.0/i;
        if(Sr > k){
			cout << i;
			return 0;
		}
    }
    return 0;
}
