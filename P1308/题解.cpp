#include <cstring>
#include <cctype>
#include <cstdio>

void strlower (char *a) {//手写函数，将大写字母转换成小写字母
    for(int i = 0; a[i]; i ++ ) {
        if(isupper(a[i])) a[i] = tolower(a[i]);//isupper是判断是否是大写字母的系统函数，tolower是将其转换成小写字母的函数
    }
}

int main () {

    char destination[1000001], *q, source[11], *p;//destintion是要找的文章，source是要找的单词，p和q都是指针类，分别代表当前搜索到什么地方了和最后一次找到单词的指针
    bool flag = false;//判断是否找到了
    int ans = 0, ans1 = -1;//个数和首次出现的位置，ans1的初值是-1是因为在没找到的时候就直接输出就行了，省事

    gets(source);
    gets(destination);//输入

    strlower(destination);//全部转换成小写字母
    strlower(source);

    int len = strlen(source);//长度，在后面防止越界和加快速度

    p = destination;//先将指针设为全部

    for(; q = strstr(p, source); ) {//循环，strstr是在一个字符串里面给定一个字符串，寻找有没有这个字符串，若有，返回首次出现的指针否则返回NULL（空指针）
        if( q != NULL//找到了 
        && ( q == destination || *(q - 1) == ' ') //第一个条件是防止越界，第二个是判断前一个是不是空格
        && ( *(q + len) == '\0' || *(q + len) == ' ' ) ) {//如果后面也是空格
            ans ++ ;//答案加一
            if(flag == false) {//如果是首次找到
                flag = true;
                ans1 = q - destination;//第一个位置
            }
        }
        p = q + len;//刷新指针
    }

    if(flag == true)//找到了
        printf("%d %d" , ans, ans1);//输出
    else 
        printf("%d", ans1);//输出-1

    return 0;
}

/*#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string sent,word;
int lens,lenw,t,pos; 
int main()
{
    getline(cin,word);  
    getline(cin,sent);   //字符串含有空格输入，不可以用cin，否则to me只能读到to 
    lenw=word.size();   
    lens=sent.size();
    for(int i=0;i<lenw;i++)
     word[i]=toupper(word[i]);  //转成大写 
    for(int i=0;i<lens;i++)
     sent[i]=toupper(sent[i]);
   t=0;
    for(int i=0;i<=lens-lenw;i++)
    {
        int j;
        for(j=0;j<lenw;++j)
        {
            if(sent[j+i]!=word[j]) break;
            if(i>0&&sent[i-1]!=' ') break;    //不是单词开头就结束 
            }
            if(j==lenw&&(sent[j+i]==' '||j+i==lens)) //单词长度匹配，后面是空格或者句末 
            {
                t++;
                if(t==1) pos=i;
            }
    }
    if(t==0)cout<<-1;
    else cout<<t<<" "<<pos;
    return 0;
}*/
