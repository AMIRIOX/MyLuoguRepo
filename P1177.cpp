#include <bits/stdc++.h>
using namespace std;
int a[100020];
inline int read(){
    int val = 0;
    int flg = 1;
    char ch = (char)getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            flg=0;
        ch = (char)getchar();
    }
    while (ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char)getchar();
    }
    return (flg?val:~(val-1));
}//快读
inline void iSwap(int& va, int& b) {
    int tmp =va;
    va =b;
    b =tmp;
}
void quickSort(int l, int r) {
    int i = l,j = r;
    int mid=a[(l+r)>>1];
    while(i<=j){
        while(a[i]<mid)i++;
        while(a[j]>mid)j--;
        if(i<=j){
            iSwap(a[i],a[j]);
            i++,j--;
        }
    }
    if(l<j) quickSort(l,j);
    if(i<r) quickSort(i,r);
}
int main(){
    int n;
    n = read();
    for(int i=0;i<n;i++){
        a[i] = read();
    }
    quickSort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    //  system("pause");
    return 0;
}
//@ $ & ^ % # *
