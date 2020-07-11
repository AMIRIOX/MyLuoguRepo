/*
 * @Author: AMIRIOX無暝 
 * @Date: 2020-04-30 22:52:45 
 * @Last Modified by:   AMIRIOX無暝 
 * @Last Modified time: 2020-04-30 22:52:45 
 */
#include <bits/stdc++.h>
using namespace std;



int n, m;

struct person {
    /* data */
    int ind;
    string zy;
} per[100001];

int main() {
    scanf("%d %d", &n, &m);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> per[i].ind >> per[i].zy;
    }
    for (int i = 0; i < m; i++) {
        int fx, step;
        scanf("%d %d", &fx, &step);
        if (fx == 0) {
            int flag = ((per[cur].ind == 0) ? -1 : 1);
            cur += (flag * step);
            if (cur < 0) cur += n;
            if (cur >= n) cur -= n;
        } else if (fx == 1) {
            int flag = ((per[cur].ind == 0) ? -1 : 1);
            cur -= flag * step;
            if (cur >= n) cur -= n;
            if (cur < 0) cur += n;
        }
    }
    puts(per[cur].zy.c_str());
    system("pause");
    return 0;
}