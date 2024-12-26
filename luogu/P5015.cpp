#include <bits/stdc++.h>
using namespace std;
int main(){
    //char ch = getchar();
    string a;
    cin >> a;
    int cnt=0;
    /*while(ch!='\n'){
        ch = getchar();
        if(ch!=' '&&ch!='\n') i++;
    }*/
    for(int i=0;i<(int)a.length();i++){
        if(a[i]!='\n'&&a[i]!=' ')
            cnt++;
    }
    cout << cnt;
    system("pause");
    return 0;
}