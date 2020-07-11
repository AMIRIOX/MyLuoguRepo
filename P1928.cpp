#include <cstdio>
#include <iostream>
using namespace std;

string pro() {
    string str,tmp;
    int ent=0;
    char ch;
    while (cin >> ch) {
        if(ch=='['){
            cin >> ent;
            tmp = pro();
            while(ent--)str+=tmp;
        }else if(ch==']'){
            return str;
        }else{
            str+=ch;
        }
    }
    return str;
}
signed main() {
    string result = pro();
    cout << result;
    return 0;
}