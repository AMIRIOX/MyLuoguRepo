#include <iostream>
#include <string>
using namespace std;
/*
ooo*o**--* o*o*o*
o--*o**oo* o*o*o*
o*o*o*--o* o*o*o*
--o*o*o*o* o*o*o*
*/
string an[] = {{"ooo*o**--*"}, {"o--*o**oo*"}, {"o*o*o*--o*"}, {"--o*o*o*o*"}};
void str_swp(string& s, long long i, long long j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
int main() {
    int n;
    cin >> n;
    string ans;
    for (int i = 0; i < n; i++) {
        ans += "o";
    }
    for (int i = 0; i < n; i++) {
        ans += "*";
    }
    ans += "--";
    cout << ans << endl;
    int ni = n;
    for (;;) {
        if (ni == 3) break;
        string::size_type pos = ans.find("--");
        string::size_type pos1 = ans.find("o*");
        if (pos == string::npos || pos1 == string::npos) throw "Data Error";
        // ans[pos] = 'o';
        // ans[pos + 1] = '*';
        // ans[pos1] = '-';
        // ans[pos1 + 1] = '-';
        str_swp(ans, pos, pos1);
        str_swp(ans, pos + 1, pos1 + 1);
        cout << ans << endl;

        if (ni == 4) break;

        // string::size_type _2pos = ans.find("**");
        string::size_type _2pos = ans.find("o*");
        ans[--_2pos] = '-';
        ans[--_2pos] = '-';
        string::size_type _3pos = ans.find("--");
        ans[_3pos] = '*';
        ans.operator[](_3pos + 1) = '*';
        cout << ans << endl;
        ni--;
        if (ni == 3) break;
    }
    ans.clear();
    for (int i = 0; i < n - 4; i++) ans += "o*";
    for (int i = 0; i < 4; i++) {
        cout << an[i] << ans << endl;
    }
    return 0;
}