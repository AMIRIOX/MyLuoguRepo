#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int isAsker[maxn], n, k;
bool suc = false;
// 返回字符串中i的个数
int rto(const string& s, int ic) {
    int cnt = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] - '0' == ic) cnt++;
    }
    return cnt;
}
bool isBalance(string s) {
    bool ok = true;
    for (int i = 0; i + k < (int)s.length(); i++) {
        int no0 = rto(s, 0);
        int no1 = rto(s, 1);
        if (no0 != no1) {
            ok = false;
            break;
        }
    }
    return ok;
}
void dfs(int cur, int maxd, string curs) {
    if (cur == maxd) {
        if (isBalance(curs)) suc = true;
        return;
    }
    string son = curs;
    son[isAsker[cur]] = 0;
    dfs(cur + 1, maxd, son);
    son[isAsker[cur]] = 1;
    dfs(cur + 1, maxd, son);
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        suc = false;
        string str;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            char ch = (char)getchar();
            str += ch;
        }
        memset(isAsker, 0, sizeof isAsker);
        int ind = 0;
        for (int i = 0; i < (int)str.length(); i++) {
            if (str[i] == '?') isAsker[ind++] = i;
        }
        dfs(0, ind, str);
        if (suc)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}