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
    int n, k, q;
    cin >> n >> k >> q;
    int p = 0;
    while ((1 << p) < n) {
        ++p;
    }

    vector<int> cnt(p, 0);
    for (int i = 0; i < k; ++i) {
        int deg;
        cin >> deg;
        ++cnt[deg];
    }

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        for (int deg = p - 1, l = 1, r = n; l != r; --deg) {
            int mid = (r + l) / 2;
            if (x <= mid) {
                int d = x - l;
                if (cnt[deg] % 2 != 0) {
                    x = mid + 1 + d;
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                int d = x - (mid + 1);
                if (cnt[deg] % 2 != 0) {
                    x = l + d;
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        cout << x << "\n";
    }
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
