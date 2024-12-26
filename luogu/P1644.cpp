#include <bits/stdc++.h>
using namespace std;
int m, n, cnt = 0;
void dfs(int x, int y) {
    // cout << x<<" "<<y<<endl;
    if (x < 0 || y < 0 || x > m || y > n) {
        // cout << "suc" << endl;
        return;
    } else if (x==m && y==n) {
        // cout << "fail" << endl;
        cnt++;
        return;
    } else {
        dfs(x + 1, y + 2);
        dfs(x + 2, y + 1);
        dfs(x + 2, y - 1);
        dfs(x + 1, y - 2);
    }
}
//Jet Brains Mono Style
int main() {
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    dfs(0, 0);
    cout << cnt;
/*@@@###***    !=  == <= >=
a b c d e f g   1 2 3 4 5
h i j k l m n   6 7 8 9 0P
o p q r s t u     A B C D E F G H
v w x y z         I J K L M N O P
, ; . / ? ]       Q R S T U V W X
( ) - + = < >         Y    Z
$ % ^ & *   */
    system("pause");
    return 0;
}