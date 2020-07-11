#include <iostream>
#include <algorithm>
using namespace std;

int n,a[1001],m[10001];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        int tmp=a[i]-a[i-1];
        m[i-1] = (tmp>=0) ? tmp : -tmp;
    }
    sort(m,m+n-1);
    int flag = 1;
    for(int i=1;i<=n-1;i++){
        if(m[i-1]!=i)flag=0;
    }
    if(flag==1) cout << "Jolly";
    else cout << "Not jolly";
    system("pause");
    return 0;
}