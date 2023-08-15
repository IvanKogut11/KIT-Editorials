#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)2e5 + 10;

ll calc_ans_for_sgn(const vector<int>& a, int sgn) {
    ll cur_ans = 0;
    ll cur_sum = 0;
    for (int x : a) {
        sgn *= -1;
        cur_sum += x;
        if (cur_sum * sgn > 0) {
            continue;
        }

        ll cur_delta = (abs(cur_sum) + 1) * sgn;
        cur_ans += abs(cur_delta);
        cur_sum += cur_delta;
    }

    return cur_ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << min(calc_ans_for_sgn(a, 1), calc_ans_for_sgn(a, -1));
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
    cout << fixed << setprecision(6);
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
