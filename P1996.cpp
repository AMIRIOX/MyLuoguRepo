
#include <cstdio>
#include <queue>
using namespace std;
queue<int> aild;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++)aild.push(i);
    while (aild.size() != 1) {
        for(int i=1;i<k;i++) {
            aild.push(aild.front());
            aild.pop();
        }
        printf("%d ",aild.front());
        aild.pop();
    }
    printf("%d",aild.front());
    return 0;
}

//! failed
// #include <iostream>
// #include <list>
// using namespace std;
// list<int> a;
// int cnt;
// int main() {
//     int n, m;
//     cin >> n, m;
//     for (int i = 1; i <= n; i++) a.push_back(i);
//     list<int>::iterator it = a.begin();
//     list<int>::iterator now;
//     while (!a.empty()) {
//         cnt++;
//         now = it;
//         if (++it == a.end()) it = a.begin();
//         // cout << "<" << *now << ">" << endl;
//         if (cnt == m) {
//             cout << *now << ' ';
//             a.erase(now);
//             cnt = 0;
//         }
//     }
//     return 0;
// }