#include <bits/stdc++.h>
using namespace std;
//狠话归狠话,学习还是要学的
int foc(int n){
    if(n==1) return 1;
    return n*foc(n-1);
}
int main(){
    int n;
    cin >> n;
    // //你不让我用循环,我偏用.嘿嘿嘿
    // for(int i=2;i<=n;i++){
    //     ans*=i;
    // }
    cout << foc(n);
    system("pause");
    return 0;
}