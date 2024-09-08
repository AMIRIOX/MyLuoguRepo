#include <bits/stdc++.h>
using namespace std;

double dist(pair<double, double> a, pair<double, double> b) {
    double x = (b.first - a.first) * (b.first - a.first);
    double y = (b.second - a.second) * (b.second - a.second);
    return sqrt(x + y); 
}

bool tcmp(vector<pair<double, double> >& v, int a, int b) {
    return v[a].second < v[b].second;
}

double mindist(vector<pair<double, double> >& v, int l, int r) {
    double mdist = 2<<20;
    if(l == r) return mdist;
    if(l + 1 == r) return dist(v[l], v[r]);
    int mid = (l + r) >> 1;
    mdist = min(mindist(v, l, mid), mindist(v, mid + 1, r));

    vector<int> mpts;
    for(int i = l; i <= r; i++)
        if(fabs(v[i].first - v[mid].first) < mdist) {
            mpts.push_back(i);
        } 

    sort(mpts.begin(), mpts.end(), [&v](const int& p1, const int& p2) { return tcmp(v, p1, p2); });
    for(int i = 0; i < mpts.size(); i++) {
        for(int j = i + 1; j < mpts.size() && fabs(v[mpts[j]].second - v[mpts[i]].second) < mdist; j++) {
            double tdist = dist(v[mpts[j]], v[mpts[i]]);
            mdist = min(mdist, tdist);
        }
    }
    return mdist;
}
signed main() {
    vector<pair<double, double> > v;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back(pair<double, double>(x, y));
    }
    sort(v.begin(), v.end(), [](const pair<double, double>& p1, const pair<double, double>& p2) { if(p1.first == p2.first) return p1.second < p2.second; else return p1.first < p2.first; });
    printf("%.4lf", mindist(v, 0, n - 1));
    return 0;
}

