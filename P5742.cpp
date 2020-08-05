#include <bits/stdc++.h>
using namespace std;
struct Student{
    int xh;
    int xy;
    int tz;
    double zh;
    int comp(){
        return xy+tz;
    }
    void js(){
        zh = (double)xy*0.7+(double)tz*0.3;
    }
}stu;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> stu.xh >> stu.xy >> stu.tz;
        stu.js();
        if(stu.comp()>140 && stu.zh>=80){
            cout << "Excellent" << endl;
        }else{
            cout << "Not excellent" << endl;
        }
    }
    system("pause");
    return 0;
}