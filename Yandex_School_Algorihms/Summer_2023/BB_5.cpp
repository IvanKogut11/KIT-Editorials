#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-4;
const int INT_INF = (int)2e9 + 10;
const ll LL_INF = (ll)1e18 + 3;

const int MAX_N = (int)5e5 + 10;

bool check(const vector<int>& v, int k) {
    int cnt_1 = 0, cnt_2 = 0;
    for (int x : v) {
        if (cnt_1 < k) {
            cnt_1 += x;
        }
        if (cnt_1 >= k) {
            cnt_2 += x;
        }
    }

    return cnt_2 >= k;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> v;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            v.push_back(cnt);
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    v.push_back(cnt);

    int l = 0, r = n + 1;
    while (r - l != 1) {
        int mid = (l + r) / 2;
        if (check(v, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
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
