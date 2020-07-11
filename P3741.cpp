#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int cnt = 0;
    int n; cin >> n;
    cin >> str;
    for(int i=0;i<(int)str.length()-1;i++){
        if(str[i]=='V'&&str[i+1]=='K'){
            str[i]=str[i+1]='_';
            cnt++;
        }
    }
    for(int i=0;i<(int)str.length()-1;i++){
        if((str[i]=='K'&&str[i+1]=='K')||(str[i]=='V'&&str[i+1]=='V')){
            str[i]=str[i+1]='_';
            cnt++;
            break;
        }
    }
    cout << cnt;
    system("pause");
    return 0;
}