#include <cstdio>
#include <iostream>
#include <string>
#define re register
using namespace std;
const int maxn = 100010;
string a, b;
void solve(string insPost, string backPost) {
    if(insPost.empty() || backPost.empty()) return;
    char root = *(--backPost.end());
    cout << root;
    string::size_type pos = insPost.find(root);
    // // cout << insPost.substr(0,pos) << endl;
    // // cout << insPost.substr(pos+1);
    // // cout << backPost.substr(0,pos) << endl;
    // // cout << backPost.substr(pos,backPost.size()-c-1) << endl;
    if (pos != string::npos) {
        int c = backPost.substr(0, pos).size();
        solve(insPost.substr(0, pos), backPost.substr(0, pos));
        solve(insPost.substr(pos + 1),
              backPost.substr(pos, backPost.size() - c - 1));
    }
}
int main() {
    cin >> a >> b;
    solve(a, b);
    cout << endl;
    return 0;
}