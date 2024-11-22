
constexpr int maxn = 2e5 + 10;

#ifdef PRESUM
int a[maxn];
int b[maxn];
void calc_prefix_sum() {
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l - 1] << " ";
    }
    endl(cout);
}
#endif

#ifdef TWODPRESUM
int a[maxn][maxn];
int sum[maxn][maxn];
inline int area(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    int ans = -0x7fffffff;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = i; k <= n; k++) {
                for(int l = j; l <= n; l++) {
                    ans = max(ans, area(i, j, k, l));
                }
            }
        }
    }
    cout << ans << endl;
#endif

#ifdef DIFF
int a[maxn]; 
int b[maxn]; 

const int n = 100;

void calc_diff() {
    for(int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        b[l]++;
        b[r + 1]--;
    }
    int cur_sum = 0;
    for(int i = 0; i <= n; i++) {
        cur += b[i];
        a[i] = cur;
    }
    cout << ans << endl;
 
}
#endif

#ifdef TWODDIFF
int a[maxn][maxn];
int b[maxn][maxn];
void calc_2d_diff() {
    for(int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        b[x1][y1]++;
        b[x2 + 1][y1]--;
        b[x1][y2 + 1]--;
        b[x2 + 1][y2 + 1]++;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            cout << b[i][j] << " ";
        }
        endl(cout);
    }
}
#endif
