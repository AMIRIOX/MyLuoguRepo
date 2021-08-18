#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
char varx[100][100];
void pre() {
    for (int i = 1; i <= 26; i++) {
        int cnt = 0;
        for (int j = i; j <= i + 26 - i; j++)
            varx[i][++cnt] = j + 64;
        char wuwu = 'A';
        for (int j = ++cnt; j <= 26; j++) 
            varx[i][j] = wuwu++;
    }
}
bool iseq(char a, char b) {
    if (a == b) return true;
    else if (abs(a - b) == 32) return true;
    return false;
}
signed main() {
    pre();
    string k, pass, ans;
    cin >> k >> pass;
    size_t ind = 0;
    for (int i = 0; i < pass.length(); i++) {
        char ks = k[ind], pos;
        bool isup = isupper(pass[i]);
        for (int j = 1; j <= 26; j++) {
            if (iseq(varx[toupper(ks) - 64][j], pass[i]))
                pos = j + 64;
        }
        if (!isup) pos = tolower(pos);
        ans += pos; ind++;
        if (ind == k.length()) ind = 0;
    }
    cout << ans << endl;
    return 0;
}