#include <cmath>
#include <cstdio>
#include <iostream>
#define PRT printf("%f %f %f\n", cx, cy, l);
#define PI acos(-1)

using namespace std;
int n;
double cx, cy, an, l;
signed main() {
    scanf("%d", &n);
    while (n--) {
        cin >> an >> l;
        if (an > 0 && an < 90) {
            an = an / 180 * PI;
            double x = cos(an) * l;
            double y = sin(an) * l;
            cx += x, cy += y;
        } else if (an > 90 && an < 180) {
            an = (180 - an);
            an = an / 180 * PI;
            double x = cos(an) * l;
            double y = sin(an) * l;
            cx -= x, cy += y;
        } else if (an > 180 && an < 270) {
            an = (270 - an);
            an = an / 180 * PI;
            double x = sin(an) * l;
            double y = cos(an) * l;
            cx -= x, cy -= y;
        } else if (an > 270 && an < 360) {
            an = (360 - an);
            an = an / 180 * PI;
            double x = cos(an) * l;
            double y = sin(an) * l;
            cx += x, cy -= y;
        } else if (an == 0 || an == 360) {
            cx += l;
        } else if (an == 90) {
            cy += l;
        } else if (an == 180) {
            cx -= l;
        } else if (an == 270) {
            cy -= l;
        }
    }
    printf("%.3f %.3f\n", cx, cy);
    return 0;
}