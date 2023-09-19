#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-4;
const int INT_INF = (int)2e9 + 10;
const ll LL_INF = (ll)1e18 + 3;

const int MAX_N = (int)3e5 + 10;

int inv_cnt[MAX_N];

vector<int> merge_sort(vector<int> a) {
    if (a.size() <= 1) {
        return a;
    }

    int mid = a.size() / 2;
    vector<int> l_a(a.begin(), a.begin() + mid), r_a(a.begin() + mid, a.end());
    l_a = merge_sort(l_a);
    r_a = merge_sort(r_a);

    int l_i = 0, r_i = 0, i = 0;
    while (l_i < l_a.size() || r_i < r_a.size()) {
        if (l_i != l_a.size() && (r_i == r_a.size() || l_a[l_i] < r_a[r_i])) {
            a[i] = l_a[l_i];
            ++l_i;
        } else {
            a[i] = r_a[r_i];
            inv_cnt[r_a[r_i]] += (int)l_a.size() - l_i;
            ++r_i;
        }
        ++i;
    }

    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    merge_sort(a);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += inv_cnt[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans << "\n";

        int l_g = inv_cnt[a[i]];
        int l_l = i - l_l;
        int r_l = a[i] - l_l, r_g = n - 1 - a[i] - l_g;
        ans += r_g - r_l - l_l + l_g;
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
