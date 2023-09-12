#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)1e6 + 10;

void solve() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a);
    for (int i = 0; i < a; ++i) {
        cin >> p[i];
    }
    vector<int> q(b);
    for (int i = 0; i < b; ++i) {
        cin >> q[i];
    }
    vector<int> r(c);
    for (int i = 0; i < c; ++i) {
        cin >> r[i];
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    ll ans = 0;
    for (int i = a - 1; i >= a - x; --i) {
        ans += p[i];
    }
    for (int i = b - 1; i >= b - y; --i) {
        ans += q[i];
    }
    for (int i = c - 1; i >= 0; --i) {
        if (x != 0 && (y == 0 || p[a - x] <= q[b - y]) && p[a - x] < r[i]) {
            ans -= p[a - x];
            --x;
            ans += r[i];
        } else if (y != 0 && (x == 0 || q[b - y] <= p[a - x]) && q[b - y] < r[i]) {
            ans -= q[b - y];
            --y;
            ans += r[i];
        } else {
            break;
        }
    }

    cout << ans;
}

void multitest() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //multitest();
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
