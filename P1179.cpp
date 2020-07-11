#include <iostream>
#define NO_RETURN_VALUE 0
using std::cin;
using std::cout;
int cnt;
int process(int n){
    int b;
    while(n>0){
        b=n%10;
        if(b==2)cnt++;
        n/=10;
    }
    return NO_RETURN_VALUE;
}
int main(){
    int a,b,c;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        c+=process(i);
    }
    cout << cnt;
    system("pause");
    return 0;;
}