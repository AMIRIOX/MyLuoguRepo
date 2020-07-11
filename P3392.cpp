#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int maxn = 105;
char a[maxn][maxn];
int n,m,ans=INT_MAX;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
                /*
                *白色i行
                *蓝色j行
                *红色k行
                */
               int _ans = 0;
               for(int q=0;q<i;q++){
                   for(int _q=0;_q<m;_q++){
                       if(a[q][_q]!='W'&&a[q][_q]!='\n'){
                           _ans++;
                       }
                        //printf("%c",a[q][_q]);
                   }
                   //printf("\n");
               }
               for(int q=i;q<j;q++){
                   for(int _q=0;_q<m;_q++){
                       if(a[q][_q]!='B'&&a[q][_q]!='\n'){
                           _ans++;
                       }
                        //printf("%c",a[q][_q]);
                   }
                   //printf("\n");
               }
               for(int q=j;q<n;q++){
                   for(int _q=0;_q<m;_q++){
                       if(a[q][_q]!='R'&&a[q][_q]!='\n'){
                           _ans++;
                       }
                       //printf("%c",a[q][_q]);
                   }
                   //printf("\n");
               }
               ans=min(ans,_ans);
               //printf("\n\n");
        }
    }
    
    printf("%d",ans);
    //system("pause");
    return 0;
}