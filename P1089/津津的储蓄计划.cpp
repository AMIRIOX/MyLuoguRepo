#include <iostream>
using namespace std;
int budget[15];
bool isGiveMum = false;
int mumHas[15];
int main(){
    int surplus = 0;
	int mumHasAll= 0;

    for(int i = 1; i <= 12; i++){
        cin >> budget[i];
        mumHas[i] = 0;
    }
    for(int i = 1; i <=12 ; i++){
    	isGiveMum = false;
    	//cout << i << " "<< budget[i] << " " <<surplus << " ";  
        if((surplus+300) < budget[i]){
            cout <<"-"<<i;
            return 0;
        }
        surplus += 300;
        int subBud = surplus - budget[i];
        while(subBud >= 100){
            mumHas[i] += 100;
            mumHasAll+= 100;
            subBud -= 100;
            isGiveMum = true;
        }
        if(!isGiveMum)
        	surplus = subBud;
        else
        	surplus = surplus-mumHas[i]-budget[i];
        //cout << surplus << " "<< mumHasAll << endl;	
    }
    cout << ((double)mumHasAll)*1.2+surplus;
    return 0;
}
