// I've spent an hour on this f**king problem,
// even if it was just a problem with `less popular` tag.
// But I realized that my effort was a piece of shit.
// In fact I haven't understood the meaning of
// this problem clearly. That's deathful.
// Now it is 23:40. I'm going to play Arknights.
// Damn Olympaid in Informatics, I love you completely.
// #include <cmath>
// #include <cstdio>
// #include <iostream>
// using namespace std;
// int n;
// signed main() {
//     scanf("%d", &n);
//     int line = (int)pow(2, n - 1);
//     int tnum_end = line * 4 / 2;
//     int cur = tnum_end - 2;
//     // int cur_t = 0;
//     int alr = 2;
//     for (int i = 1; i <= line; i++) {
//         if (i == 1) {
//             for (int j = 1; j < tnum_end; j++)
//                 printf(" ");
//             printf("/\\\n");
//             for (int j = 1; j < tnum_end - 1; j++)
//                 printf(" ");
//             printf("/__\\\n");
//         } else if (i == line) {
//             printf(" ");
//             for (int j = 1; j <= line; j++) {
//                 printf("/\\");
//                 if (j != line)
//                     printf("  ");
//             }
//             printf("\n");
//             for (int j = 1; j <= line; j++) {
//                 printf("/__\\");
//             }
//             printf("\n");
//         } else {
//             // int carry_t = (int)pow(2, cur_t);

//             for (int j = 1; j < cur; j++)
//                 printf(" ");
//             printf("/\\");
//             for (int j = 1; j <= alr+2-2; j++) {
//                 printf(" ");
//             }
//             printf("/\\\n");

//             // printf("%d %d\n",cur_t, carry_t * 4 - 1-1);

//             for (int j = 1; j < cur-1; j++)
//                 printf(" ");
//             printf("/__\\");
//             for (int j = 1; j <= alr-2; j++) {
//                 printf(" ");
//             }
//             printf("/__\\\n");

//             cur -= 2;
//             // cur_t++;
//             alr+=4;
//         }
//     }
//     return 0;
// }
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char mp[5000][5000];
int flo = 0;
void dfs(int lr, int curf, int x, int y, bool isExt) {
    if (curf > flo)
        return;

    mp[x][y] = '/';
    mp[x + 1][y] = '\\';
    mp[x - 1][y + 1] = '/';
    mp[x][y + 1] = '_';
    mp[x + 1][y + 1] = '_';
    mp[x + 2][y + 1] = '\\';

    if (curf == 2)
        cout << "(" << isExt << ")" << endl;
    if (isExt) {
        dfs(1, curf + 1, x - 2, y + 2, !isExt);
        dfs(2, curf + 1, x + 2, y + 2, !isExt);
    } else {
        if (lr == 1)
            dfs(0, curf + 1, x - 2, y + 2, !isExt);
        else if (lr == 2)
            dfs(0, curf + 1, x + 2, y + 2, !isExt);
    }

    // if (lr == 1) {
    //     dfs(1, curf + 1, x - 2, y + 2, !isExt);
    // } else if (lr == 2) {
    //     dfs(2, curf + 1, x + 4, y + 2, !isExt);
    // } else if (lr == 0) {
    //     dfs(1, curf + 1, x - 2, y + 2, !isExt);
    //     dfs(2, curf + 1, x + 2, y + 2, !isExt);
    // }
}
signed main() {
    for (int i = 1; i < 5000; i++) {
        for (int j = 1; j < 5000; j++) {
            mp[i][j] = '*';
        }
    }
    int n;
    scanf("%d", &n);
    flo = int(pow(2, n)) / 2;
    dfs(0, 1, flo * 4 / 2, 1, true);
    int cnt = flo * 4 / 2 + 1;
    for (int j = 1; j <= flo * 2; j++) {
        for (int i = 1; i <= cnt; i++) {
            if (mp[i][j] == '*')
                printf(" ");
            else
                printf("%c", mp[i][j]);
        }
        printf("\n");
        cnt++;
    }
    return 0;
}