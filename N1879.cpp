#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, p[250];
char v[250], tmp[250];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int m;
    while (cin >> m) {
        if (!m)
            break;
        scanf("%s", v);
        for(int i=strlen(v);i<=n;i++){
            v[i]=' ';
        }
        while (m--) {
            for (int x = 1; x <= n; x++) {
                tmp[p[x] - 1] = v[x - 1];
            }
            strcpy(v, tmp);
            for (int i = 0; i < strlen(tmp); i++)
                tmp[i] = ' ';
        }
        cout << v << endl;
    }
    return 0;
}

// #include <cstdio>
// #include <iostream>
// using namespace std;
// int p[250];
// char str[250], ans[250];
// int main() {
//     int n, m, v;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> v;
//         p[i] = v - 1;
//     }
//     while (cin >> m) {
//         if (m == 0)
//             break;
//         cin >> str;
//         int len = strlen(str);
//         for (int i = len; i < n; i++) {
//             str[i] = ' ';
//         }
//         for (int i = 0; i < m; i++) {
//             for (int i = 0; i < n; i++)
//                 ans[p[i]] = str[i];
//             strcpy(str, ans);
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }