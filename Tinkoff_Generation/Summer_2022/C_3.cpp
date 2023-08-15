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
    getline(cin, s);
    int n = s.size();
    int first_c = -1;
    for (int i = 0; i < n; ++i) {
        if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z') {
            if (first_c == -1) {
                first_c = i;
            }
            continue;
        }

        if (first_c != -1) {
            cout << s[first_c];
            if (i - first_c > 2) {
                string t = s.substr(first_c + 1, i - first_c - 2);
                for (int j = 0; j + 1 < t.size(); ++j) {
                    if (t[j] != t[j + 1]) {
                        swap(t[j], t[j + 1]);
                        break;
                    }
                }
                cout << t;
            }
            if (i - first_c > 1) {
                cout << s[i - 1];
            }

            first_c = -1;
        }
        cout << s[i];
    }

    if (first_c != -1) {
        cout << s[first_c];
        if (n - first_c > 2) {
            string t = s.substr(first_c + 1, n - first_c - 2);
            for (int j = 0; j + 1 < t.size(); ++j) {
                if (t[j] != t[j + 1]) {
                    swap(t[j], t[j + 1]);
                    break;
                }
            }
            cout << t;
        }
        if (n - first_c > 1) {
            cout << s[n - 1];
        }
    }

    cout << "\n";
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
