/*
 * @Author: AMIRIOX無暝 
 * @Date: 2020-05-03 22:02:32 
 * @Last Modified by: AMIRIOX無暝
 * @Last Modified time: 2020-05-03 22:10:30
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
char a[10001];
int main(){
    while(scanf("%s",a+1)==1){
        int cur=0,last=0,nex[10001];
        nex[0]=0;
        memset(nex,0,sizeof(nex));
        for(int i=1;i<=(int)strlen(a+1);i++){
            if(a[i]=='[')cur=0;
            else if(a[i]==']')cur=last;
            else{
                nex[i]=nex[cur];
                nex[cur]=i;
                if(cur==last)last=i;
                cur=i;
            }
        }
        for(int i=nex[0];i!=0;i=nex[i]){
            cout << a[i];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstring>
// #include <cstdio>
// #include <queue>

// using namespace std;
// const int maxn= 100006;
// char s[maxn];
// int next1[maxn];
// int main()
// {
//     while(scanf("%s",s+1)!=EOF)
//     {
//         memset(next1,0,sizeof(next1));//next数组中放的是右边的下标
//         int len = (int)strlen (s+1);
//         int cur=0,last=0;
//         for(int i=1;i<=len;i++)
//         {
//             if(s[i]=='[') cur=0;//放到最前面
//             else if(s[i]==']') cur=last;//回归正常
//             else
//             {
//                 next1[i]=next1[cur];//先i的右边等于 cur的右边
//                 next1[cur]=i;//cur 等于 i  （相当于将cur与之前的联系去掉了）
//                 if(last==cur) last=i;//紧跟
//                 cur=i;
//             }
//         }
//         for(int i=next1[0];i;i=next1[i])
//             printf("%c",s[i]);
//         printf("\n");
//     }
//     return 0;
// }
