#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("out.txt","w",stdout);
    int n, x, y;
    string tmp, last;
    char ctrl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (!(cin >> x)) {
            cin.clear();
            cin >> ctrl >> x;
        }
        cin >> y;
        switch (ctrl) {
            case 'a': {
                last += to_string(x) + '+' + to_string(y) + '=';
                last += to_string(x + y);
                cout << last << endl << last.length() << endl;
                last.clear();
                break;
            }
            case 'b': {
                last += to_string(x) + '-' + to_string(y) + '=';
                last += to_string(x - y);
                cout << last << endl << last.length() << endl;
                last.clear();
                break;
            }
            case 'c': {
                last += to_string(x) + '*' + to_string(y) + '=';
                last += to_string(x * y);
                cout << last << endl << last.length() << endl;
                last.clear();
                break;
            }
        }

        // getline(cin, tmp);
        // if (tmp[0] >= '0' && tmp[0] <= '9') {
        //     int index = 0;  string nums; string nums2;
        //     while(tmp[index]!=' '&& tmp[index]!='\n')
        //         nums+=tmp[index++];
        //     index++;
        //     while(tmp[index]!=' '&& tmp[index]!='\n')
        //         nums2+=tmp[index++];
        //     cout << nums << nums2;
        //     // switch(ctrl){
        //     //     case 'a':{

        //     //     }
        //     //     case 'b':{

        //     //     }
        //     //     case 'c':{

        //     //     }
        //     // }
        // } else if (tmp[0] >= 'a' && tmp[0] <= 'z') {
        //     //ctrl = tmp[0];
        //     int index = 2;  string nums; string nums2;
        //     while(tmp[index]!=' '&& tmp[index]!='\n')
        //         nums+=tmp[index++];
        //     index++;
        //     while(tmp[index]!=' '&& tmp[index]!='\n')
        //         nums2+=tmp[index++];
        //     cout << nums << nums2;
        //     // switch(ctrl){
        //     //     case 'a':{

        //     //     }
        //     //     case 'b':{

        //     //     }
        //     //     case 'c':{

        //     //     }
        //     // }
        // }
    }

    system("pause");
    return 0;
}