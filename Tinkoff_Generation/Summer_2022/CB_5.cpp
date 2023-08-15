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
    int n, X;
    cin >> n >> X;
    vector<pair<int, int>> ab(n);
    ll min_sum = 0, max_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].first >> ab[i].second;
        min_sum += ab[i].first;
        max_sum += ab[i].second;
    }

    if (X < min_sum || X > max_sum) {
        cout << -1;
        return;
    }

    ll rem = X - min_sum;
    ll current_shark = 1;
    for (int i = 0; i < n; ++i) {
        ll right_shark = current_shark + ab[i].first - 1;
        right_shark += min(rem, (ll)ab[i].second - ab[i].first);
        rem -= min(rem, (ll)ab[i].second - ab[i].first);

        cout << current_shark << " " << right_shark << "\n";

        current_shark = right_shark + 1;
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
