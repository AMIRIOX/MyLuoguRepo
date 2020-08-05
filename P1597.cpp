#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> m;
    m[0]=0,m[1]=0,m[2]=0;
    char tmp,tmp2;
    while(scanf("%c:=%c;",&tmp,&tmp2)==2){
        if(tmp2=='a'||tmp2=='b'||tmp2=='c'){
            m[tmp-'a']=m[tmp2-'a'];
        }else{
            m[tmp-'a']=tmp2-'0';
        }
    }
    //sort(m.begin(),m.end());
    for(auto iv=m.begin();iv!=m.end();iv++){
        cout << iv->second <<" ";
    }
    system("pause");
    return 0;
}