//! 雪耻!

//* 失败代码
// #define _CRT_SECURE_NO_WARNINGS
// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <set>
// using namespace std;
// int main() {
//     freopen("p.out", "w", stdout);
//     set<int> s;
//     int cs;
//     cin >> cs;
//     int a, al;
//     for (int i = 0; i < cs; i++) {
//         cin >> a >> al;
//         if (a == 1) {
//             if (s.count(al))
//                 cout << "Already Exist" << endl;
//             else
//                 s.insert(al);
//         } else {
//             if (s.empty()) {
//                 cout << "Empty" << endl;
//                 continue;
//             }
//             if (s.count(al)) {
//                 s.erase(al);
//                 cout << al << endl;
//             } else {
//                 if (s.empty()) {
//                     cout << "Empty" << endl;
//                     continue;
//                 }
//                 int dis = -1;
//                 int dis2 = -1;
//                 for (int i = al; i >= 0; i--) {
//                     if (s.count(i)) {
//                         dis = i;
//                         break;
//                     }
//                 }
//                 for (int i = al; i <= 1000000000; i++) {
//                     if (s.count(i)) {
//                         dis2 = i;
//                         break;
//                     }
//                 }
//                 int res;
//                 if (dis == -1) {
//                     res = dis2;
//                 } else if (dis2 == -1) {
//                     res = dis;
//                 } else if (dis2 != -1 && dis != -1) {
//                     res = ((al - dis == dis2 - al) ? min(dis, dis2)
//                                                    : min(al - dis, dis2 - al));
//                 }

//                 cout << res << endl;
//                 s.erase(res);
//             }
//         }
//     }
//     return 0;
// }

//* 成功代码
#include <iostream>
#include <set>
using namespace std;
int n, cmd, leng;
set<int> s;
int main() {
    cin >> n;
    while (n--) {
        cin >> cmd >> leng;
        if (cmd == 1) {
            if (s.find(leng) != s.end())
                cout << "Already Exist" << endl;
            else
                s.insert(leng);
        } else if (s.empty()) {
            cout << "Empty" << endl;
        } else {
            set<int>::iterator pos = s.lower_bound(leng), ans = pos;
            if (ans != s.begin()) ans--;
            if (pos != s.end() && leng - (*ans) > (*pos) - leng) ans = pos;
            cout << (*ans) << endl;
            s.erase(ans);
        }
    }
    return 0;
}