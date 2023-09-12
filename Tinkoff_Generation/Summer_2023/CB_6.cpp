#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)1e6 + 10;

int calc_off_days_to_use(int l, int r, int w, const vector<bool>& is_off_day) {
    int off_days_to_use = 0;
    for (int d = l, c = 1; d <= r; ++d) {
        if ((d + w) % 7 >= 5) {
            ++off_days_to_use;
        }
        if (is_off_day[d]) {
            c = 1;
            continue;
        }
        if (c == 7) {
            --off_days_to_use;
            c = 1;
            continue;
        }

        ++c;
    }

    return off_days_to_use;
}

bool check(int ans, int days_cnt, int w, const vector<bool>& is_off_day) {
    for (int l = 0; l <= days_cnt - ans; ++l) {
        int r = l + ans - 1;
        int off_days_to_use = 0;
        off_days_to_use += calc_off_days_to_use(0, l - 1, w, is_off_day);
        off_days_to_use += calc_off_days_to_use(r + 1, days_cnt - 1, w, is_off_day);
        for (int i = l; i <= r; ++i) {
            off_days_to_use += (w + i) % 7 >= 5;
            off_days_to_use += is_off_day[i];
        }
        if (r - l + 1 <= off_days_to_use) {
            return true;
        }
    }

    return false;
}

void solve() {
    int y, w;
    cin >> y >> w;
    --w;
    vector<int> days = {
            31, 28, 31, 30,
            31, 30, 31, 31,
            30, 31, 30, 31
    };
    days[1] += (y % 4 == 0);
    int days_cnt = 365 + (y % 4 == 0);

    int n;
    cin >> n;
    vector<bool> is_off_day(days_cnt, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int d = atoi(s.substr(0, 2).c_str()), m = atoi(s.substr(3).c_str());
        int day = d - 1;
        for (int j = 0; j < m - 1; ++j) {
            day += days[j];
        }
        is_off_day[day] = true;
    }

    int l = 0, r = days_cnt + 1;
    while (r - l != 1) {
        int mid = (l + r) / 2;
        if (check(mid, days_cnt, w, is_off_day)) {
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
