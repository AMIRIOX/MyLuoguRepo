#include <bits/stdc++.h>
using namespace std;
char ch;
int n = -1, status = 0, cnt = 0, ind = 0;
string out,tmp;
int ans[10001];
int main() {
    cin >> out;
    n = out.size();
    ch = '0';
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        out+=tmp;
    }
    status = ((out[0]) ^ 48);
    for (int i = 0; i <= out.size(); i++) {
        if (((out[i]) ^ 48) == status) {
            cnt++;
        } else {
            ans[ind++] = cnt;
            cnt=1;
            status = ((out[i]) ^ 48);
        }
    }
    cout << n << " ";
    if(out[0]=='1')cout <<"0 ";
    for (int i = 0; i < ind; i++) {
        cout << ans[i] << " ";
    }
    system("pause");
    return 0;
}