#include <bits/stdc++.h>
using namespace std;
int years[1001];
int main(){
    int l,r,cnt=0;
    cin >> l >> r;
    for(int i=l;i<=r;i++){
        if((i%4==0 && i%100!=0)||(i%400==0)){
            years[cnt++]=i;
        }
    }
    cout << cnt <<endl;
    for(int i=0;i<cnt;i++){
        cout << years[i]<<" ";
    }
    system("pause");
    return 0;
}