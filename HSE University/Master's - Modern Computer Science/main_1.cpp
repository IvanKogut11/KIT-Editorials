#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int INT_INF = (int)2e8 + 300;

void solve() {
    // Read input
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;

        // Modify coordinates to work with integers
        points[i].first *= 2;
        points[i].second *= 2;
    }

    // Find min and max x coordinate
    int min_x = INT_INF, max_x = -INT_INF;
    for (const auto& point : points) {
        min_x = min(min_x, point.first);
        max_x = max(max_x, point.first);
    }

    // Calculate axis of symmetry
    int x_sym = (max_x + min_x) / 2;

    // Check every point for having reflected point
    map<pair<int, int>, int> points_balance;
    for (auto point : points) {
        if (point.first > x_sym) {
            --points_balance[{2 * x_sym - point.first, point.second}];
        } else {
            ++points_balance[point];
        }
    }

    for (const auto& [point, point_balance] : points_balance) {
        if (point_balance != 0) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

