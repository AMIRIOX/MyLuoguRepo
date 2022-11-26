#include <iostream>
using namespace std;
bool eating[100], anscon[100];
int n, cnt, ans;
int main() {
    cin >> n;
    string v;
    cin >> v;
    for (int i = 0; i < v.length(); i++) {
        if (eating[v[i]]) {
            // leave
            eating[v[i]] = false;
            cnt--;
        } else {
            // come
            if (cnt < n) {  // enough
                cnt++;
                eating[v[i]] = true;
            } else {  // answer
                if (!anscon[v[i]]) {
                    anscon[v[i]]=true;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}