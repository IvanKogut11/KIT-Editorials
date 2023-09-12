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
    vector<string> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<string> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }
    vector<int> d(m + 1);
    for (int i = 0; i < m + 1; ++i) {
        cin >> d[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int add = d[0];
        for (int j = 0; j < m; ++j) {
            if (t[i] == q[j]) {
                add = d[j + 1];
                break;
            }
        }
        ans += add;
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
