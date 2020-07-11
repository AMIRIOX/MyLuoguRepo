#include <bits/stdc++.h>
using namespace std;
int A[120];
int B[120];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    B[0]=A[0];
    for(int i=1;i<n;i++){
        B[i]=B[i-1]+A[i];
    }
    for(int i=0;i<n;i++){
        cout << B[i]<<" ";
    }
    system("pause");
    return 0;
}