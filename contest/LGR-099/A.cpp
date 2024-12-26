#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q[200];
string s;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < x.length(); j++) {
            q[i].push(x[j] - '0');
        }
    }
    int cur = q[1].front();
    s.push_back(q[1].front() + '0');
    int ans = 0;
    bool exec = false;
    bool _nnep = false;
    bool changed = false;

    for (int i = 1; i <= n; i++) {
        if (!q[i].empty() && q[i].front() == cur) {
            exec = true;
            s.push_back(q[i].front() + '0');
            q[i].pop();
            if (!changed)
                ans++;
            changed = false;
        }
        if (!q[i].empty())
            _nnep = true;
        if (i == n && _nnep) {
            // cout << "fuck you stupid code" << endl;
            // 缺少两个1可能是两种情况 （1）被跳过了 （2）被强制跳出循环了
            i = 1;
            if (!exec) {
                cur = !cur;
                changed = true;
            }
            _nnep = false;
            exec = false;
        }
    }
    printf("%d\n", ans);
    cout << s;
    return 0;
}