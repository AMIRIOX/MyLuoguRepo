#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int num;
int main() {
    char cur;
    do {
        cur = getchar();
        if (/*isdigit(cur)*/ cur >= '0' && cur <= '9') {
            num = num * 10 + cur - '0';
        } else if (cur == '.') {
            s.push(num), num = 0;
        } else if (cur != '@') {
            int lft = s.top();
            s.pop();
            int rit = s.top();
            s.pop();
            switch (cur) {
                case '+':
                    s.push(rit + lft);
                    break;
                case '-':
                    s.push(rit - lft);
                    break;
                case '*':
                    s.push(rit * lft);
                    break;
                case '/':
                    s.push(rit / lft);
                    break;
            }
        }
    } while (cur != '@');
    cout << s.top() << endl;
    return 0;
}