#include <bits/stdc++.h>
using namespace std;
int fil[100][100];
int main(){
    int n;
    cin >> n;
    int x=0,y=-1,f=1;
    while(f<=n*n){
        while(y<n-1&&fil[x][y+1]==0)fil[x][++y]=f++;
        while(x<n-1&&fil[x+1][y]==0)fil[++x][y]=f++;
        while(y>0&&fil[x][y-1]==0)fil[x][--y]=f++;
        while(x>0&&fil[x-1][y]==0)fil[--x][y]=f++;
    }
    cout.setf(ios::fixed);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout <<fixed<<setw(3)<<setfill(' ')<< fil[i][j];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}