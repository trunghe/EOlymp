#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

bool comp(ii p1, ii p2) {
    return p1.first < p2.first
           || (p1.first == p2.first && p1.second < p2.second);
}

void solve() {
    int c;
    cin >> c;
//    cout << "c = " << c << endl;
    ii arr[c];
    FOR(i, 0, c) {
        cin >> arr[i].first >> arr[i].second;
//        cout << arr[i].first << ' ' << arr[i].second << endl;
    }
    if (c > 1) {
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n, comp);
        FOR(i, 1, c) {
//        cout << arr[i].first << ' ' << arr[i].second << endl;
            if (arr[i].first >= arr[i - 1].second) {
                cout << "NO" << endl;
                return;
            }
            arr[i].first = min(arr[i].first, arr[i - 1].first);
            arr[i].second = max(arr[i].second, arr[i - 1].second);
        }
    }
    cout << "YES" << endl;
}


int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    int TC;
    cin >> TC;
//    cout << TC << endl;
    FOR(tc, 0, TC) {
        // Process each testcase here
        solve();
    }

    return 0;
}

/*
Input example #1
2
1
1 2
2
1 2
3 4
Output example #1
YES
NO
 */
