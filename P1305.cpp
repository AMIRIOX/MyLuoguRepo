#include <iostream>
#include <string>
#define MAXN 100010
using namespace std;
int main() {
    int n;
    cin >> n;
    string ans;
    cin >> ans;
    for(int i=2;i<=n;i++) {
        string tmp;
        cin >> tmp;
        string::size_type pos = ans.find(tmp[0]);
        if(pos!=string::npos) ans.erase(pos,1);
        ans.insert(pos,tmp);
        //ans+=tmp;
    }
    for(int i=0;i<ans.size();i++) if(ans[i]!='*') cout << ans[i];
    return 0;
}