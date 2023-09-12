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
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        ans += c[i];
    }
    sort(c.begin(), c.end());

    vector<pair<int, int>> l_d(m);
    for (int i = 0; i < m; ++i) {
        cin >> l_d[i].first;
    }
    for (int i = 0; i < m; ++i) {
        cin >> l_d[i].second;
    }
    sort(l_d.begin(), l_d.end());

    priority_queue<int> h;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && l_d[j].first <= c[i]) {
            h.push(l_d[j].second);
            ++j;
        }
        if (!h.empty()) {
            ans -= h.top();
            h.pop();
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
