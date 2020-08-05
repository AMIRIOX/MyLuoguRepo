// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,tmp,sum=0;
//     cin >> n;
//     for(int i=0;i<n;i++){
//         cin >> tmp;

//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int ans[7], zj[7], sum = 0, tmp;
int main() {
    memset(ans,0,7);
    int n;
    cin >> n;
    for (int i = 0; i < 7; i++) {
        cin >> zj[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> tmp;
            for (int k = 0; k < 7; k++) {
                if (tmp == zj[k]) {
                    sum++;
                    break;
                }
            }
        }
        ans[sum]++;
        sum = 0;
    }
    for (int i = 7; i >0; i--) {
        cout << ans[i] << " ";
    }
    system("pause");
    return 0;
}