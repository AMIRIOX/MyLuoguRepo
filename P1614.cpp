#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[4000];
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    //sort(arr,arr+n);
    int ans = INT_MAX,tmp=0;
    for(int i=0;i<(n-m+1);i++){
        for(int j=0;j<m;j++){
            tmp += arr[i+j];
        }
        ans = ans<tmp?ans:tmp;
        tmp = 0;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
