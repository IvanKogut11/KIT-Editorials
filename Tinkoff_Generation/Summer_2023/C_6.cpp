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
    ll x;
    int l;
    cin >> x >> l;
    if (l == 1) {
        cout << x + 1;
        return;
    }
    ll ans = LL_INF;
    for (int d = 2; ; ++d) {
        ll dl = 1;
        bool f = false;
        for (int i = 1; i <= l; ++i) {
            dl *= d;
            if (dl > ans) {
                f = true;
                break;
            }
        }

        if (f) {
            break;
        }

        ll cur_ans = (x / dl + 1) * dl;

        ans = min(ans, cur_ans);
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
