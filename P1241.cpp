#include <cstdio>
#include <iostream>
#include <stack>
#define int long long
using namespace std;
const int maxn = 1e3 + 10;
string x;
char pls[maxn];
stack<char> s;
bool isLeft(char a) {
    if (a == '(' || a == '[') return true;
    return false;
}
bool isRight(char a) {
    if (a == ')' || a == ']') return true;
    return false;
}
char trans(char a) {
    if (a == '(') return ')';
    if (a == '[') return ']';
    if (a == ')') return '(';
    if (a == ']') return '[';
}
signed main() {
    cin >> x;
    for (int i = 0; i < x.length(); i++) {
        if (isLeft(x[i])) {
            s.push(i);
            pls[i] = trans(x[i]);
        } else {
            if (s.empty() || pls[s.top()] != x[i]) {
                pls[i] = trans(x[i]);
            } else {
                pls[s.top()] = '$';
                s.pop();
            }
        }
    }
    for (int i = 0; i < x.length(); i++) {
        if (isLeft(pls[i])) printf("%c", pls[i]);
        cout << x[i];
        if (isRight(pls[i])) printf("%c", pls[i]);
    }
    return 0;
}