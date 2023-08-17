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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.rbegin(), a.rend());
    vector<int> cnt_to_use(n, 2);
    vector<int> ans(n, -1);
    ans[a[0].second] = 0;
    int j = 0;
    for (int i = 1; i < n; ++i) {
        bool f = false;
        for (; j < i; ++j) {
            if (a[j].first - a[i].first < k) {
                break;
            }
            if (cnt_to_use[j] != 0) {
                f = true;
                --cnt_to_use[j];
                ans[a[i].second] = a[j].second + 1;
                break;
            }
        }
        if (!f) {
            cout << -1;
            return;
        }
    }

    for (int x : ans) {
        cout << x << " ";
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
