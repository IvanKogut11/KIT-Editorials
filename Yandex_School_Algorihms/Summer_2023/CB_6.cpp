#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 1;
const ll LL_INF = (ll)1e18 + 3;

const int MAX_N = (int)1000 + 10;

struct Cake {
    ll t, d, c;

    ll get_sum() {
        return t + d + c;
    }

    bool operator<(Cake other) {
        return get_sum() < other.get_sum();
    }
};

ll get_ans(vector<Cake> a, int m, int s_t, int s_d, int s_c) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        a[i].t *= s_t;
        a[i].d *= s_d;
        a[i].c *= s_c;
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = n - 1; i >= n - m; --i) {
        ans += a[i].get_sum();
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Cake> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].t >> a[i].d >> a[i].c;
    }

    ll ans = 0;
    for (int s_t = -1; s_t <= 1; s_t += 2) {
        for (int s_d = -1; s_d <= 1; s_d += 2) {
            for (int s_c = -1; s_c <= 1; s_c += 2) {
                ans = max(ans, get_ans(a, m, s_t, s_d, s_c));
            }
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
    //cout << fixed << setprecision(10);
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
