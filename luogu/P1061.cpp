#include <iostream>
using namespace std;
string W;
int s, t, w;
char words[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void proc() {
    int tag = -1;
    char x;
    for (int i = w - 1; i >= 0; i--) {
        if ((W[i] + 1 <= words[t]) && ((W[i] + 1) != W[i + 1])) {
            W[i] = W[i] + 1;
            tag = i + 1;
            x = W[i];
            break;
        }
    }
    if (tag != -1) {
        for (int i = tag; i < w; i++) {
            while ((W[i] - 1) != x) {
                W[i] = W[i] - 1;
            }
            x = W[i];
        }
    }
    cout << W << endl;
}
signed main() {
    cin >> s >> t >> w >> W;
    for (int i = 1; i <= 5; i++)
        proc();
    return 0;
}