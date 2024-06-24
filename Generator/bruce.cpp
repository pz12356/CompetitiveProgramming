#include <bits/stdc++.h>
//#define int long long
#define double long double
using namespace std;
const int N = 2e5 + 10;
struct Link {
    double x, y, cnt1, cnt2;
} a[N];
double si1, co1;
bool cmp1(Link xx, Link yy) {
    return xx.x + xx.y < yy.x + yy.y;
}
bool cmp2(Link xx, Link yy) {
    return xx.x - xx.y < yy.x - yy.y;
}
double si, co;
void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%Lf%Lf", &a[i].x, &a[i].y);
        a[i].cnt1 = -a[i].x * si - a[i].y * co;
        a[i].cnt2 = a[i].x * si1 + a[i].y * co1;
    }
    int flag = 0;
    double ans = 0.0, minn = 8e18;
    for (int i = 1; i <= n - 1; i++) {
        if (fabs(a[i].x - a[i + 1].x) <= 1e-16)
            ;
        else
            flag++;
    }
    if (!flag) {
        ans = 1.0;
        printf("%.10Lf\n", ans);
        return;
    }
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n - 1; i++) {
        double x1 = a[i].x, y1 = a[i].y, x2 = a[i + 1].x, y2 = a[i + 1].y;
        if (fabs(x1 - x2) <= 1e-16) {

        } else {
            ans = max(ans,
                      (fabs(x1 - x2) + fabs(y1 - y2)) /
                          sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        }
    }
    sort(a + 1, a + n + 1, cmp2);
    for (int i = 1; i <= n - 1; i++) {
        double x1 = a[i].x, y1 = a[i].y, x2 = a[i + 1].x, y2 = a[i + 1].y;
        if (fabs(x1 - x2) <= 1e-16) {

        } else {
            ans = max(ans,
                      (fabs(x1 - x2) + fabs(y1 - y2)) /
                          sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        }
    }
    // cout<<ans<<"\n";
    printf("%.10Lf\n", ans);
    // cout<<fixed<<setprecision(12)<<ans<<'\n';
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr),cout.tie(nullptr);
    double PI = acosl(-1);
    double ang = 7 * 1.0 * PI / 4;
    double ang1 = PI * 1.0 / 4;
    si1 = sinl(ang1), co = cosl(ang1);
    si = sinl(ang), co = cosl(ang);
    int _;
    _ = 1;
    scanf("%d", &_);
    while (_--) {
        solve();
    }
}