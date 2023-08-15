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
    vector<int> days = {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    string s;
    cin >> s;
    vector<int> v = {
            atoi(s.substr(0, 2).c_str()),
            atoi(s.substr(3, 2).c_str()),
            atoi(s.substr(6, 2).c_str())
    };
    sort(v.begin(), v.end());

    vector<vector<int>> ans;
    for (bool f = true; f; f = next_permutation(v.begin(), v.end())) {
        if (v[1] < 1 || v[1] > 12) {
            continue;
        }
        int cur_year = v[2] == 0 ? 2100 : 2000 + v[2];
        bool is_leap_year = cur_year % 4 == 0 && cur_year % 100 != 0 || cur_year % 400 == 0;
        int cur_days = days[v[1] - 1] + (v[1] == 2 && is_leap_year);
        if (v[0] < 1 || v[0] > cur_days) {
            continue;
        }
        ans.push_back(v);
    }

    if (ans.empty()) {
        cout << "No such date";
        return;
    }

    for (auto v : ans) {
        cout << setw(2) << setfill('0') << v[0] << "/";
        cout << setw(2) << setfill('0') << v[1] << "/";
        cout << setw(2) << setfill('0') << v[2] << "\n";
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
