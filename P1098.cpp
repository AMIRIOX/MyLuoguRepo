#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int p1, p2, p3;
string s;
string r;
bool notStyle(char a, char b) {
    if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) &&
        (b >= '0' && b <= '9')) {
        return false;
    } else if (((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z')) &&
               (a >= '0' && a <= '9')) {
        return false;
    } else {
        return true;
    }
}
char toElse(char src) {
    if (src >= 'A' && src <= 'Z' && p1 == 1) {
        return char(int(src) + 32);
    } else if (src >= 'a' && src <= 'z' && p1 == 2) {
        return char(int(src) - 32);
    } else if (p1 != 3) {
        return src;
    } else if (p1 == 3) {
        return '*';
    }
    return src;
}
int main() {
    // freopen("out.txt","w",stdout);
    scanf("%d%d%d", &p1, &p2, &p3);
    cin >> s;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '-') {
            if(i==(int)s.length()-1 || i==0){
                r+='-';
                continue;
            }else if(s[i-1]=='-' || s[i+1]=='-'){
                r+='-';
                continue;
            }
            int asc = (int)s[i - 1];
            int asc2 = (int)s[i + 1];
            // cout << asc << " " << asc2;
            if ((int)asc >= (int)asc2) {
                r += s[i];
            } else if (!notStyle(s[i-1],s[i+1])) {
                r += s[i];
            } else {
                if (p3 == 1) {
                    while ((++asc) < asc2) {
                        for (int j = 0; j < p2; j++) r += toElse((char)asc);
                    }
                } else if (p3 == 2) {
                    while ((--asc2) > asc) {
                        for (int j = 0; j < p2; j++) r += toElse((char)asc2);
                    }
                }
            }
        } else {
            r += s[i];
            // cout << s[i] << endl;
        }
    }
    cout << r;
    system("pause");
    return 0;
}