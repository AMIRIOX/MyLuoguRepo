#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
int dpl[10020];
stack<char> s;
bool noans = true;
int maxans = -0x7fffffff;
int maxnu = 0;
bool match(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    return false;
}
signed main() {
    string str;
    cin >> str;
    bool flag = false;
    s.push(str[0]);
    //if (str[0] == '(')
      //  flag = true;
    for (int i = 1; i < str.length(); i++) {
        // if(i==73) printf("%d\n____\n", dpl[i-1]);
        printf("%2d ",dpl[i-1]);
        if (!s.empty() && match(s.top(), str[i])) {
            if (flag) {
                dpl[i] = dpl[i - 1] + 2;
                noans=false;
                if (dpl[i] > maxans) {
                    maxans = dpl[i];
                    maxnu = 0;
                }
                if (dpl[i] == maxans)
                    maxnu++;
            } else {
                dpl[i] = 2;
                flag = true;
                noans=false;
                if (dpl[i] > maxans) {
                    maxans = dpl[i];
                    maxnu = 0;
                }
                if (dpl[i] == maxans)
                    maxnu++;
            }
            s.pop();
        } else {
            if (str[i] == '(') {
                dpl[i] = dpl[i - 1];
                s.push('(');
            } else {
                dpl[i] = 0;
                flag = false;
            }
        }
    }
    puts("");
    for(int i=0;i<str.length()-1; i++) {
        printf("%2d ", i);
    }
    if(!noans) printf("%d %d\n", maxans, maxnu);
    else printf("0 1\n");
    return 0;
}