#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)1e6 + 10;

int cnt[MAX_N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int c, x;
        cin >> c >> x;
        cnt[x] = c;
    }

    int cur_sum = 0;
    for (int i = (int)1e6; i >= max(0, (int)1e6 - 2 * k); --i) {
        cur_sum += cnt[i];
    }
    int ans = cur_sum;

    for (int i = (int)1e6 - 2 * k - 1; i >= 0; --i) {
        cur_sum -= cnt[i + 2 * k + 1];
        cur_sum += cnt[i];
        ans = max(ans, cur_sum);
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

