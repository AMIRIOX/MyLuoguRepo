#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int n, k;
int a[50000020];
void quickSort(int left, int right) {
    int i = left, j = right, m = a[(left + right) / 2];
    while (i <= j) {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    //! left  j  i   right 
    if(k<=j) quickSort(left,j);
    else if(k>=i) quickSort(i,right);
    else {
        printf("%d",a[j+1]);
        return ;
    }
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //sort(a, a + n);
    /*k++;
    for(int i=0;i<n;i++){
        if(i==0 || a[i]!=a[i-1]) k--;
        if(k==0) printf("%d ",a[i]);
        return 0;
    }*/
    quickSort(0,n-1);
    //system("pause");
    return 0;
}