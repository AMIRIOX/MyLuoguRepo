#include <iostream>
using namespace std;

int main(){
    int k = 0;
    cin >> k;
    int n = 1;
    
    double Sn = 0;
    for(int i=1; Sn <= k+1; i++){
        Sn += 1.0/i;
        //cout << "+"<<"1/"<<i << "= "<<Sn;
        if(Sn > k){
			cout << i << endl << Sn;
			return 0;
		}
    }
    return 0;
}
