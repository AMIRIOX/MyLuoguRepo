#include <bits/stdc++.h>
using namespace std;
char lei[110][110];
char ans[110][110];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> lei[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt = 0;
            if(i-1>=0 && lei[i-1][j]=='*'){
                cnt++;
            }
            if(i+1<=n && lei[i+1][j]=='*'){
                cnt++;
            }
            
        }
    }
    system("pause");
    return 0;
}