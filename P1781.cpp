#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
struct t
{
    int ind;
    string val;
    bool operator<(const t& b) const{
        if(val.length()!=b.val.length()){
            return val.length() < b.val.length();
        }
        return val < b.val;
    }
    bool operator>(const t& b) const{
        if(val.length()!=b.val.length()){
            return val.length() > b.val.length();
        }
        return val > b.val;
    }
}nu[100001];
int main(){
    //int n;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        nu[i].ind=i+1;
        cin >> nu[i].val;
    }
    sort(nu,nu+n);
    // //printf("%d\n%d",nu[n-2].ind,nu[n-2].val);
    // for(int i=0;i<n;i++){
    //    cout << nu[i].ind <<" "<< nu[i].val << endl;
    // }
    cout << nu[n-1].ind << endl << nu[n-1].val;
    system("pause");
    return 0;
}