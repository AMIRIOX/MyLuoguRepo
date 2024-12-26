#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 10001
using namespace std;

int src;
int res;
int ans[MAXN];
void multi(int* a, int* b, int c[]) {
    memset(c, 0, MAXN);
    for (int i = 1; i <= a[0]; i++) {
        for (int j = 1; j <= b[0]; j++) {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }
    c[0] = a[0] + b[0] + 1;
    while (c[0] > 1 && c[c[0]] == 0) c[0]--;
    //memset(c, 0, sizeof(c)*4);
	// for (int i = 1; i <= a[0]; i++) {
	// 	for (int j = 1; j <= b[0]; j++) {
	// 		c[i + j - 1] += a[i] * b[j];
	// 		c[i + j] += c[i + j - 1] / 10;
	// 		c[i + j - 1] %= 10;
	// 	}
	// }
	// int len = a[0] + b[0] + 1;
	
	// while ((c[len] == 0) && (len > 1)) len--;
	// c[0]=len;
}
void chai(int* a, int num) {
    a[0] = (int)log10(num) + 1;
    int ind = 1;
    while (num != 0) {
        a[ind++] = num % 10;
        num /= 10;
    }
}
void outputResult(int* result) {
    for (int i = result[0]; i > 0; i--) {
        printf("%d", result[i]);
    }
}
int main() {
    {
        scanf("%d", &src);
        int ind = 0;
        for (int i = 2; res < src; i++) {
            ans[ind++] = i;
            res += i;
        }
        if (res == src) {
            int result[MAXN]{1, 1};
            for (int i = 0; i < ind; i++) {
                printf("%d ", ans[i]);
                int tmp[MAXN];
                for (int j = 0; j <= result[0]; j++) tmp[j] = result[j];
                int tmp3[MAXN];
                chai(tmp3, ans[i]);
                //printf("\n");
                //outputResult(tmp);
                //printf("*");
                //outputResult(tmp3);
                //printf("=");
                multi(tmp, tmp3, result);
                //outputResult(result);
            }
            printf("\n");
            outputResult(result);
        } else {
            int tmp2 = res - src;
            if (tmp2 == 1) {
                ans[ind]++;
                int result[MAXN]{1, 1};
                for (int i = 0; i < ind; i++) {
                    printf("%d ", ans[i]);
                    int tmp[MAXN];
                    for (int j = 0; j <= result[0]; j++) tmp[j] = result[j];
                    int tmp3[MAXN];
                    chai(tmp3, ans[i]);
                    //printf("\n");
                    //outputResult(tmp);
                    //printf("*");
                    //outputResult(tmp3);
                    //printf("=");
                    multi(tmp, tmp3, result);
                    //outputResult(result);
                    
                }
            printf("\n");
            outputResult(result);
            } else {
                int result[MAXN]{1, 1};
                for (int i = 0; i < ind; i++) {
                    if (ans[i] != tmp2) {
                        printf("%d ", ans[i]);
                        int tmp[MAXN];
                        for (int j = 0; j <= result[0]; j++) tmp[j] = result[j];
                        int tmp3[MAXN];
                        chai(tmp3, ans[i]);
                        //printf("\n");
                        //outputResult(tmp);
                        //printf("*");
                        //outputResult(tmp3);
                        //printf("=");
                        multi(tmp, tmp3, result);
                        //outputResult(result);
                        
                    }
                }
                printf("\n");
                outputResult(result);
                // printf("\n%lld", result);
                //printf("\n");
            }
        }
    }

    system("pause");
    return 0;
}