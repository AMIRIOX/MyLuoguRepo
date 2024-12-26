#include <iostream>
#include <cstdio>
std::string taskplace[100010];
int a[100010];
void turn_add(int &cur, int n, int ny) {
    if((cur + ny) == n) cur = n;
    else cur = (cur + ny) % n;
}
void turn_minu(int &cur, int n, int  ny) {
    if(cur + (n - ny) == n) cur = (((cur - ny) > 0) ? cur - ny : n);
    else cur = (((cur - ny) > 0) ? cur - ny : ((cur + (n - ny) % n)));
}
int main() {
    int n, m, cur = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        std::cin >> taskplace[i];
    }
    // printf("%s\n", taskplace[20].c_str());
    for(int i = 1; i <= m; i++) {
        int lr, ny;
        scanf("%d %d", &lr, &ny);
        if(lr == 0 && a[cur] == 0) {
            turn_minu(cur, n, ny);
        } else if(lr == 0 && a[cur] == 1) {
            turn_add(cur, n, ny);
        } else if(lr == 1 && a[cur] == 0) {
            turn_add(cur, n, ny);
        } else if(lr == 1 && a[cur] == 1) {
            turn_minu(cur, n, ny);
        }	
        // printf("%d ",cur);
        // puts(taskplace[cur].c_str());
    }
    printf("%s\n", taskplace[cur].c_str());
    return 0;
}