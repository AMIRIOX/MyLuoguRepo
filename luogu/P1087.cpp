#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char checkFBI(string s) {
    bool is0=true, is1=true;
    for(string::iterator i=s.begin(); i!=s.end(); i++) {
        if((*i)=='1') is0=false;
        if((*i)=='0') is1=false;
    }
    if(is0) return 'B';
    else if(is1) return 'I';
    else return 'F';
}
void build(string s) {
    int len = (int)s.length();
    if(len<=1) {
        cout << checkFBI(s);
        return;
    }
    build(s.substr(0, len/2));
    build(s.substr(len/2, len/2));
    cout << checkFBI(s);
}
int main() {
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    build(s);
    printf("\n");
    return 0;
}