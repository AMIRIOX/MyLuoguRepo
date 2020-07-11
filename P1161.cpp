#include <bits/stdc++.h>
using namespace std;
bool sobig[100000001];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        double a;int b;
        cin >> a >> b;
        for(int j=1;j<=b;j++){
            int idx = (int)(a*j);
            sobig[idx] = !sobig[idx];
        }
    }
    for(int i=0;i<100000001;i++){
        if(sobig[i]==1){
            cout << i <<endl;
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}