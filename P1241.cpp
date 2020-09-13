#include <cstdio>
#include <iostream>
#include <stack>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
string x;
char trans(char a) {
    if (a == '(') return ')';
    if (a == '[') return ']';
    // if (a == '{') return '}';
    return a;
}
signed main() {
    cin >> x;
    stack<char> s;
    for (int i = 0; i < x.length(); i++) {
        if (!s.empty() && x[i] == trans(s.top()))
            s.pop();
        else
            s.push(x[i]);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}