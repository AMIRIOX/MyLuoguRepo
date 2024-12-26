#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> s;
string p;
char trans(char org) {
    if (org == ')') return '(';
    if (org == ']') return '[';
    if (org == '}') return '{';
    return '\0';
}
int main() {
    int que;
    cin >> que;
    getline(cin, p);
    while (que--) {
        while (!s.empty()) s.pop();
        getline(cin, p);
        for (int i = 0; i < p.size(); i++) {
            if (s.empty())
                s.push(p[i]);
            else if (trans(p[i]) == s.top())
                s.pop();
            else
                s.push(p[i]);
        }
        cout << ((s.empty()) ? "Yes\n" : "No\n");
    }
    return 0;
}