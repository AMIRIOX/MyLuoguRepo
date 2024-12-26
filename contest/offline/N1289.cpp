#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int n, cnt;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, p;
        cin >> x >> p;
        if (p)
            s.push(x);
        else {
            while (!s.empty() && s.top() <= x) {
                s.pop();
            }
            if (s.empty())
                cnt++;
        }
    }
    cout << s.size()+cnt << endl;
    return 0;
}