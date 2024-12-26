/*

  0 0 0 0 | 0 0 0 1
  0 0 0 0 | 0 0 1 1
  0 0 0 0 | 0 1 0 1
  0 0 0 0 | 1 1 1 1
  --------⊙--------
  0 0 0 1 | 0 0 0 1
  0 0 1 1 | 0 0 1 1
  0 1 0 1 | 0 1 0 1
  1 1 1 1 | 1 1 1 1

*/
#include <bits/stdc++.h>
using namespace std;
int mat[1025][1025];
void process(int n, int is, int js) {
    cout <<"called:"<< n <<" "<< is <<" "<< js << endl;
    if (n <= 1) return;
    for (int i = is; i < n/2+is; i++) {
        for (int j=js; j < n/2+js; j++) {
            mat[i][j] = 1;
        }
    }
    process(n / 2, is + n / 2, js);
    process(n / 2, is, js + n / 2);
    process(n / 2, is + n / 2, js + n / 2);
}
int main() {
    int n;
    cin >> n;
    int sign = (int)pow(2, n);
    //memset(mat, 1, sign * sign);
    process(sign, 0, 0);
    for (int i = 0; i < sign; i++) {
        for (int j = 0; j < sign; j++) {
            cout << (mat[i][j]==1?0:1) << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}