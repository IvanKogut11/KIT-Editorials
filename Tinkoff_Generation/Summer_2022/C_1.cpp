#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)2e5 + 10;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int best_ans = INT_INF;

    for (int i = 0; i < 26; ++i) {
        bool f = false;
        for (auto c : s) {
            if ((c - 'a') == i) {
                f = true;
                break;
            }
        }
        if (!f) {
            continue;
        }

        string t = s;
        for (int cur_ans = 0; cur_ans < n; ++cur_ans) {
            bool not_i = false;
            for (auto c : t) {
                if ((c - 'a') != i) {
                    not_i = true;
                    break;
                }
            }
            if (!not_i) {
                best_ans = min(best_ans, cur_ans);
                break;
            }
            
            for (int j = 0; j + 1 < t.size(); ++j) {
                if ((t[j] - 'a') != i && (t[j + 1] - 'a') == i) {
                    t[j] = 'a' + i;
                }
            }
            t.pop_back();
        }
    }

    cout << best_ans;
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
