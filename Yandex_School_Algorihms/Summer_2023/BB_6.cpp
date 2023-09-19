#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-4;
const int INT_INF = (int)2e9 + 10;
const ll LL_INF = (ll)1e18 + 3;

const int MAX_N = (int)5e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;

        ans += a[i].first;
    }
    if (n == 1) {
        cout << a[0].second << "\n";
        return;
    }

    sort(a.begin(), a.end(), [](pair<int, int> lhs, pair<int, int> rhs) {
        return lhs.second - lhs.first > rhs.second - rhs.first;
    });

    for (int i = 0; i < n - 1; ++i) {
        ll add = a[i].second - a[i].first;
        if (i == n - 2) {
            add += a[n - 1].second - a[n - 1].first;
        }
        if (add <= 0) {
            break;
        }

        int l = n - i - 1, r = m - 2 * i;
        if (l + 1 < r) {
            ans += add;
        } else {
            break;
        }
    }

    cout << ans << "\n";
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
    multitest();
    //solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
