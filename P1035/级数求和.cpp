#include <iostream>
using namespace std;
double S_n(int r){
    double Sr = 0;
    for(int i=1; i<=r; i++){
        Sr += 1.0/i;
    }
    return Sr;
}

int main(){
    int k;
    cin >> k;
    for(int n = 1;;n++){
        double Sn = S_n(n);
        //cout <<" ";
		if(Sn > (double)k){
        	cout << n;
            break;
        }
    }
    return 0;
}
