#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main(){
    double a,b,c;
    cin >> a >> b >> c;
    int res = (int)(a*0.2+b*0.3+c*0.5);
    cout << res;
    system("pause");
    return 0;
}