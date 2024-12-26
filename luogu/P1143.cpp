#include <iostream>
using namespace std;
char itcTransfer(int x) {
    return ((x<=9) ? x+'0' : x-10+'A');
}
int ctiTransfer(char c) {
    if(c>='0' && c<='9') {
        return c-'0';
    }else {
        return c-'A'+10;
    }
}
int main() {
    int n, m, output[20010],tmp=0,cnt=0;
    string num;
    cin >> n >> num >> m;

    // cover n to 10
    for(int i=0;i<num.length();i++) {
        tmp = tmp*n+ctiTransfer(num[i]);
    }

    // cover 10 to m
    while(tmp) {
        output[cnt++]=tmp%m,tmp/=m;
    }
    for(int i=cnt-1;i>=0;i--) {
        cout << itcTransfer(output[i]);
    }
    return 0;
}