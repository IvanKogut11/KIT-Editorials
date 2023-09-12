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
    map<int, int> cnt;
    int min_ai = INT_INF, max_cnt = 0, max_cnt_ai = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];    
        if (cnt[a[i]] > max_cnt) {
            max_cnt = cnt[a[i]];
            max_cnt_ai = a[i];
        }
        min_ai = min(min_ai, a[i]);
    }

    if (max_cnt > (n + 1) / 2 || max_cnt == (n + 1) / 2 && max_cnt_ai != min_ai) {
        cout << "No";
    } else {
        cout << "Yes";
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
