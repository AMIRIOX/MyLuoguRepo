#include <iostream>
using namespace std;
int sub1(int n) {
    // 2 0207
    int first = n/10000; //1
    int second = n%10000/1000;  //2
    int third = n%1000/100;   //3
    // cout << first << " " << second << " " << third << " " <<endl; 
    return first*100+second*10+third;
}
int sub2(int n) {    
    // 20207
    int first = n%10000/1000; //2
    int second = n%1000/100;  //3
    int third = n%100/10;   //4
    // cout << first << " " << second << " " << third << " " <<endl; 

    return first*100+second*10+third;

}
int sub3(int n) {
    // 20207
    int first = n%1000/100; //3
    int second = n%100/10;  //4
    int third = n%10/1;   //5
    // cout << first << " " << second << " " << third << " " <<endl; 

    return first*100+second*10+third;
}
int main(void) {
    int k;
    cin >> k;
    const int s = 10000;
    const int e = 30000;
    bool ok = false;
    for(int i=s; i<=e; i++) {
        int s1=sub1(i);
        int s2=sub2(i);
        int s3=sub3(i);

        if(/*i==s1+s2+s3 &&*/ s1%k==0 && s2%k==0 && s3%k==0) {
            cout << i << endl;
            ok = true;
        }
    }
    if(!ok) cout << "No" << endl;
    return 0;
}