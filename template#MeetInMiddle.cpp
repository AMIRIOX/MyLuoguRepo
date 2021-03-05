#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct xf {
    int x, y;
    string stu;
    xf(int _x, int _y, string _s) : x(_x), y(_y), stu(_s) {}
};
const string aim = "";   //TODO
int mov[8][2] = {};      //TODO
bool onebfs(string status, int sxi, int syi) {
    map<string, int> onemp;
    queue<xf> q;
    q.push(xf(sxi, syi, status));
    while (!q.empty()) {
    }
    return false;
}
void twobfs() {
    map<string, int> twomp;
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        string maps;
        int sx, sy;
        for (int i = 1; i <= 5; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < 5; j++) {
                if (tmp[j] == '*')
                    sx = i, sy = j + 1;
            }
            maps += tmp;
        }
        if (!onebfs(maps, sx, sy))
            twobfs();
    }
    return 0;
}