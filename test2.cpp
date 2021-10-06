#include <iostream>
using namespace std;
string words[30];
// void makeEdge(int a, int b) {
//     for (int i = words[a].length() - 1; i >= 0; i--) {
//         if (words[a][i] == words[b][0]) {
//             int pt = 0;
//             for (int j = i; j < words[a].length(); j++) {
//                 if (pt >= words[b].length() || words[a][j] != words[b][pt++])
//                     goto BRK;
//             }
//             if (/*(words[a] == words[b] && pt != words[a].length()) ||
//                 (words[a].find(words[b]) == string::npos &&
//                  words[b].find(words[a]) == string::npos)*/
//                 (words[a] == words[b] && pt != words[a].length()) ||
//                 (words[a].find(words[b]) == string::npos &&
//                  words[b].find(words[a]) == string::npos)) {
//                 cout << words[a] << " link to " << words[b]
//                      << ", val= " << words[b].length() - pt << endl;
//                 return;
//             }
//         }
//     BRK:
//         continue;
//     }
// }

void makeEdge(int a, int b) {
    for (int i = words[a].length() - 1; i >= 0; i--) {
        if (words[a][i] == words[b][0]) {
            int pt = 0;
            for (int j = i; j < words[a].length(); j++) {
                if (pt >= words[b].length() || words[a][j] != words[b][pt++])
                    goto BRK;
            }
            if ((words[a] == words[b] && pt != words[a].length()) ||
                (words[a].find(words[b]) == string::npos &&
                 words[b].find(words[a]) == string::npos)) {
                if (words[a] == words[b] && words[b] == string("tact"))
                    printf("???\n");

                cout << words[a] << " link to " << words[b]
                     << ", val= " << words[b].length() - pt << endl;
                // addEdge(a, b, words[b].length() - pt);
                return;
            }
        }
    BRK:
        continue;
    }
}
signed main() {
    words[1] = "tact";
    // words[2] = "tact";
    makeEdge(1, 1);
}