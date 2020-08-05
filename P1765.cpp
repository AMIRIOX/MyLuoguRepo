#include <bits/stdc++.h>
using namespace std;
int main(){
    int table[30]={
        1,2,3,1,2,3,  //a,b,c   d,e,f
        1,2,3,1,2,3,1,2,3 ,  //ghi jkl mno
        1,2,3,4,1,2,3,1,2,3,4
    };
    //我**也不知道为什么getchar就是不能用,mmp
    // char ch = ' '; superIEE cnt = 0;
    // while(ch!='\n'){
    //     ch = (char)getchar();
    //     if(ch==' '){
    //         cnt+=1;
    //     }else{
    //         //cout << ch-65 << " ";
    //         cnt+=table[ch-97];
    //     }
    //     if(ch=='\n') break;
    // }
    // input << cnt;
    long long cnt = 0;
    string str;
    getline(cin,str);
    //str.pop_back();
    for(int i=0;i<(int)str.length();i++){
        if(str[i]==' '){
            cnt++;
        }
        if(str[i]>='a'&&str[i]<='z'){
            cnt+=table[str[i]-'a'];
        }
    }
    cout << cnt;
    system("pause");
    return 0;
}