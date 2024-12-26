#include <iostream>
using namespace std;
int coin[2020]; 
int n;
void rev_modify() {
    for(int i=1; i<=n; i++) {
        if(coin[i]==1) coin[i]=0;
        else coin[i]=1;
    }
}  
int main() {
    cin >> n;
    cout << n << endl;;
    for(int i=1; i<=n; i++) {
        if(coin[i]==1) coin[i]=0;
        else coin[i]=1;
        rev_modify();
        for(int i=1;i<=n;i++) {
            cout << coin[i];
        }
        cout << endl;
    }
    return 0;
}