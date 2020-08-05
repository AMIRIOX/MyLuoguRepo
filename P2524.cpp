#include <bits/stdc++.h>
using namespace std;
char a[15]{};
int n=0;
const int foc[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(int bit){
    int cval=0;
    for(int i=0;i<bit;i++){
        int smaller=0;
        for(int j=i+1;j<bit;j++){
            if(a[j]<a[i])smaller++;
        }
        //cout <<"ans+= "<< smaller << "*"<<n<<"!"<< endl;
        cval+=smaller*foc[bit-i-1];
    }
    return cval+1;
}
int main(){
    cin >> n;
    cin >> a;
    cout << cantor(n);
    system("pause");
    return 0;
}