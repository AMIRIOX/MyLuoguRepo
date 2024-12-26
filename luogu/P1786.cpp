#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> m;
int n; string junk;
struct bang {
    string name;
    long long bg;
    int level;
    string work;
    int ind;
} a[10001];

bool cmp1(bang ba, bang bb) {
    if (ba.bg != bb.bg) return ba.bg > bb.bg;
    // else if(a.level!=b.level) return a.level > b.level;
    else
        return ba.ind < bb.ind;
}

bool cmp2(bang a_, bang b_) {
    if(a_.work!=b_.work) return m[a_.work] < m[b_.work];
    else if(a_.level!=b_.level) return a_.level > b_.level;
    else return a_.ind < b_.ind;
}
void giveWork() {
    for (int i = 0; i < n; i++) {
        if (i == 0)
            a[i].work = "BangZhu";
        else if (i == 1 || i == 2)
            a[i].work = "FuBangZhu";
        else if (i == 3 || i == 4)
            a[i].work = "HuFa";
        else if (i >= 5 && i <= 8)
            a[i].work = "ZhangLao";
        else if (i >= 9 && i <= 15)
            a[i].work = "TangZhu";
        else if (i >= 16 && i <= 40)
            a[i].work = "JingYing";
        else
            a[i].work = "BangZhong";
    }
}
int main() {
    m["BangZhu"]= 0;
	m["FuBangZhu"]=1;
	m["HuFa"]=2;
	m["ZhangLao"]=3;
	m["TangZhu"]=4;
	m["JingYing"]=5;
	m["BangZhong"]=6;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        cin >> a[i].name >> junk;
        scanf("%lld %d",&a[i].bg,&a[i].level);
        a[i].ind = i;
    }
    sort(a+3,a+n,cmp1);
    giveWork();
    sort(a,a+n,cmp2);
    for(int i=0;i<n;i++){
        printf("%s %s %d\n",a[i].name.c_str(),a[i].work.c_str(),a[i].level);
    }
    system("pause");
    return 0;
}