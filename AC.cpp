#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100010;
int C[MAXN][MAXN],n,m;
int main() {
    cin >> n >> m;
    for(int i=0;i<=21;i++) {
        C[i][0]=C[i][i]=0;
        for(int j=1;j<i;j++) {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    for(int i=0;i<=20;i++) {
        for(int j=0;j<=i;j++) {
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
    cout << C[n][m];
    return 0;
}