#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n;
vector<string> ups, downs;
map<int, string> sames;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string song, con;
        cin >> song >> con;
        if (con == "UP") {
            ups.push_back(song);
        } else if (con == "DOWN") {
            downs.push_back(song);
        } else if (con == "SAME") {
            sames[i] = song;
        }
    }
    int upcnt = 0;
    int downcnt = 0;
    for (int cnt = 1; cnt <= n; cnt++) {
        if (sames.find(cnt) != sames.end())
            cout << sames[cnt] << endl;
        else if (downcnt < downs.size())
            cout << downs[downcnt++] << endl;
        else if (upcnt < ups.size())
            cout << ups[upcnt++] << endl;
    }
    return 0;
}