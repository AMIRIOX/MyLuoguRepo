#include <iostream>
#include <queue>
using namespace std;
int n, ans, flg;
priority_queue<int, vector<int>, greater<int> > qwq;
priority_queue<int, vector<int>, greater<int> > qaq;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        qwq.push(tmp);
    }
    //cout << qwq.size();
    while (qwq.size()>1) {
        int a = qwq.top();
        qwq.pop();
        //cout << "pop" << " " << a << endl;
        if(qwq.empty()){
            ans+=a;
            qwq.push(a);
            //cout << "qwq.push" << a  << "=" << ans << endl;
            break;
        }
        int b = qwq.top();
        qwq.pop();
        //cout << "pop" << " " << b << endl;
        ans+=(a+b);
        qwq.push(a+b);
        //cout << "qwq.push" << a <<"+"<< b << "=" << a+b <<"="<< ans<< endl;
        //cout << "ans+" << a << "+"<< b << "+" << t1 << "=" << ans << endl;
    }
    cout << ans;
    return 0;
}