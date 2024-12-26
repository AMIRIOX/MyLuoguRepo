#include <bits/stdc++.h>
using namespace std;
int score[1000];
signed main() {
    char a, b, c;
    cin >> a >> b >> c;
    if(a == '<' && b == '<' && c == '<')
        cout << 'B' << endl;
    else if(a == '<' && b == '>' && c =='>')
        cout << 'A' << endl;
    else if(a == '<' && b == '<' && c == '>')
        cout << 'C' << endl;
    else if(a == '>' && b == '<' && c == '<')
        cout << 'A' << endl;
    else if(a == '>' && b == '>' && c == '<')
        cout << 'C' << endl;
    else if(a == '>' && b == '>' && c == '>')
        cout << 'B' << endl;
    return 0;
}
