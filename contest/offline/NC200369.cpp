#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n, t;
    cin >> n >> t;
    string num; cin >> num;
    // 从小数点后一位开始枚举，枚举到
    // 第一个能够五入的位置就进位然后往回依次进位， t--;
    bool afterdot = false, _of = false;
    int endp = num.length() - 1;
    for(int i = 0; i < num.length(); i++) {
        if(afterdot && num[i] - '0' >= 5) {
            for(int j = i; j - 1 >= 0; j--){
                if(num[j] - '0' >= 5) {
                    t--;
                    if(num[j - 1] == '.') {
                        // [j - 2, 0]
                        endp = j - 2;
                        int x = j - 2;
                        for(; x >= 0 && num[x] == '9'; x--) {
                            num[x] = '0';
                        }
                        if(x < 0) _of = true;
                        else num[x]++;
                        
                        break; 
                    }
                    else num[j - 1]++, endp = j - 1;
                    if(t <= 0) break;
                }else break;
            }
            break;
        }
        if(num[i] == '.') afterdot = true;
    }
    if(_of) cout << 1;
    for(int i = 0; i <= endp; i++) cout << num[i];
    cout << endl;
    return 0;
}
