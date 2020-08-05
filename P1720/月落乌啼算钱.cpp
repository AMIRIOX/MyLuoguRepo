#include <iostream>
#include <cmath>
//#include <iomanip>
#include <cstdio>
using namespace std;
int main(){
    float n;
    cin >> n;
    //cout << setiosflags(ios::fixed)<<setprecision(2); 
    //cout << pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n)/sqrt(5)<<endl;
    printf("%.2f",(pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5)); 

    return 0;
}
