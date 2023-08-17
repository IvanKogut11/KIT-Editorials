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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pref_ones(n);
    pref_ones[0] = (a[0] == 1);
    for (int i = 1; i < n; ++i) {
        pref_ones[i] = pref_ones[i - 1] + (a[i] == 1);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int ones_cnt = pref_ones[r];
        if (l != 0) {
            ones_cnt -= pref_ones[l - 1];
        }
        if (ones_cnt == r - l + 1) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
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
