#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    int cnt=0,cnt2=0;
    cin >> a;
    for(int i=0;i<((int)a.length())-2;i++){
        if(a[i]=='b'||a[i+1]=='o'||a[i+2]=='y') cnt++;
    }
    for(int i=0;i<((int)a.length())-3;i++){
        if(a[i]=='g'||a[i+1]=='i'||a[i+2]=='r'||a[i+3]=='l') cnt2++;
    }
    cout << cnt << endl << cnt2;
    system("pause");
    return 0;
}