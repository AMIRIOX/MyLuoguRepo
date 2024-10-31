#include <bits/stdc++.h>
using namespace std;

string process() {
    char c;
    string ans;
    while(cin >> c && c != ']') {
        if(c == '[') {
            int n; cin >> n;
            string tmp = process();
            while(n--) ans += tmp;
        }else {
            ans += c;
        }
    }
    return ans;
}
signed main() {
    cout << process() << endl;
    return 0;
}
