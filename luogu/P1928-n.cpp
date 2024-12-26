#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string process() {
    string ret, tmp;    
    char ch;
    while(cin>>ch) {
        if(ch=='[') {
            int n = 0;
            cin >> n;
            tmp = process();
            while(n--) ret+=tmp;
        }else if(ch==']') {
            return ret;
        }else {
            ret+=ch;
        }
    }
    return ret;
}
signed main() {
    cout << process();
    return 0;
}