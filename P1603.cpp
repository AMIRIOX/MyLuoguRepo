#include <bits/stdc++.h>
using namespace std;
long long cnt = 0,ans_s_s=0;
long long ans_s[1001];
void ans(string s) {
    if (s == "two" || s == "both" || s == "second") {
        ans_s[cnt] = 4;
        cnt++;
        return;
    }
    if (s == "one" || s == "a" || s == "first" || s == "another") {
        ans_s[cnt] = 1;
        cnt++;
        return;
    }
    if (s == "three" || s == "third") {
        ans_s[cnt] = 9;
        cnt++;
        return;
    }
    if (s == "four") {
        ans_s[cnt] = 16;
        cnt++;
        return;
    }
    if (s == "five") {
        ans_s[cnt] = 25;
        cnt++;
        return;
    }
    if (s == "six") {
        ans_s[cnt] = 36;
        cnt++;
        return;
    }
    if (s == "seven") {
        ans_s[cnt] = 49;
        cnt++;
        return;
    }
    if (s == "eight") {
        ans_s[cnt] = 64;
        cnt++;
        return;
    }
    if (s == "nine") {
        ans_s[cnt] = 81;
        cnt++;
        return;
    }
    if (s == "eleven") {
        ans_s[cnt] = 21;
        cnt++;
        return;
    }
    if (s == "twelve") {
        ans_s[cnt] = 44;
        cnt++;
        return;
    }
    if (s == "thirteen") {
        ans_s[cnt] = 69;
        cnt++;
        return;
    }
    if (s == "fourteen") {
        ans_s[cnt] = 96;
        cnt++;
        return;
    }
    if (s == "fifteen") {
        ans_s[cnt] = 25;
        cnt++;
        return;
    }
    if (s == "sixteen") {
        ans_s[cnt] = 56;
        cnt++;
        return;
    }
    if (s == "seventeen") {
        ans_s[cnt] = 89;
        cnt++;
        return;
    }
    if (s == "eightteen") {
        ans_s[cnt] = 24;
        cnt++;
        return;
    }
    if (s == "nineteen") {
        ans_s[cnt] = 61;
        cnt++;
        return;
    }
}
int main() {
    string s;
    for(int i=0;i<6;i++){
        cin >> s;
        if(*(s.end())-1=='.'){
            s.pop_back();
            cout << "("<<s<<")";
        }
        ans(s);  
    }
    sort(ans_s,ans_s+cnt);
    for(int i=0;i<cnt;i++){
        ans_s_s+=ans_s[i];
        ans_s_s*=100;
    }
    cout << ans_s_s/100;
    system("pause");
    return 0;
}//我是个人