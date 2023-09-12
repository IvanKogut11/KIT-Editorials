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
    vector<pair<int, int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };
    int n;
    cin >> n;
    int x = 0, y = 0;
    int speed = 0, cur_dir = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "Stop") {
            speed = 0;
        } else if (speed == 0) {
            if (s == "Fwrd") {
                speed = 100;
            } else if (s == "Back") {
                speed = -100;
            } else if (s == "Rght") {
                cur_dir = (cur_dir + 1) % 4;
            } else if (s == "Left") {
                cur_dir = (cur_dir - 1 + 4) % 4;
            }
        } else if (speed > 0) {
            if (s == "More") {
                speed = min(speed + 100, 500);
            } else if (s == "Less") {
                speed -= 100;
            }
        }

        x += dirs[cur_dir].first * speed;
        y += dirs[cur_dir].second * speed;
    }

    cout << x << " " << y;
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
