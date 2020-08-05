#include <bits/stdc++.h>
using namespace std;
bool isp(int num){
    if(num==1) return false;
    if(num<=3) return true;
    for(int i=2;i*i<=num;i++){
        if(num%i==0)return false;
    }
    return true;
}
int main(){
    int n,tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(isp(tmp))cout << tmp<<" ";
    }
    system("pause");
    return 0;
}