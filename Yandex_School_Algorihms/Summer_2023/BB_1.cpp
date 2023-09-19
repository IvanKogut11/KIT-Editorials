#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-4;
const int INT_INF = (int)2e9 + 10;
const ll LL_INF = (ll)1e18 + 3;

const int MAX_N = (int)1000 + 10;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());
    int r = INT_INF;
    for (int i = 1; i < n; ++i) {
        if (a[i].second != a[i - 1].second) {
            r = min(r, a[i].first - a[i - 1].first);
        }
    }
    --r;

    int ans = a[0].second == 1;
    for (int i = 1; i < n; ++i) {
        if (a[i].second == 1 && (a[i - 1].second == 0 || a[i].first - a[i - 1].first > r)) {
            ++ans;
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
