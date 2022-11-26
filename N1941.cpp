#include <cmath>
#include <iostream>
using namespace std;
string command;
int now, x, y;
int main() {
    cin >> command;
    //      N
    //   W     E
    //      S
    for (int i = 0; i < command.length(); i++) {
        if (command[i] >= '0' && command[i] <= '9')
            now = now * 10 + command[i] - '0';
        // 注意不要把方向写错了（重复）
        else if (command[i] == 'N')
            y += now;
        else if (command[i] == 'S')
            y -= now;
        else if (command[i] == 'W')
            x -= now;
        else if (command[i] == 'E')
            x += now;
        else if (command[i] == ',')
            now = 0;
    }
    cout << abs(x) + abs(y) << endl; // 注意绝对值！
    return 0;
}