#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n,a,b,c;
    char last,s[20],ans[20];
    scanf("%d\n",&n);
    while( n-- ) {
        fgets(s,sizeof s, stdin);
        if(s[0]=='a' || s[0]=='b' || s[0]=='c') {
            last = s[0],s[0]=' ';
        }
        sscanf(s,"%d %d",&a,&b);
        switch (last)
        {
        case 'a':c=a+b;sprintf(ans,"%d+%d=%d",a,b,c);break; //+
        case 'b':c=a-b;sprintf(ans,"%d-%d=%d",a,b,c);break; //-
        case 'c':c=a*b;sprintf(ans,"%d*%d=%d",a,b,c);break; //*
        }
        printf("%s\n%d\n",ans,strlen(ans));
    }
    return 0;
}