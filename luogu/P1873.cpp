#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,arr[1000020];
int isOk(int num){
    long long add = 0;
    for(int i=0;i<n;i++){
        add+=((arr[i]>num)?((long long)(arr[i]-num)):0);
    }
    return add>=m;
}
int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int start=1,end=100000000;
    while(start!=end-1){
        int tmp =((start+end)>>1);
        if(isOk(tmp)){
            start=tmp;
        }else{
            end=tmp;
        }
    }
    cout << start;
    system("pause");
    return 0;
}