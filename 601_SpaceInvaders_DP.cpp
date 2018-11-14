#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    int n, p;
    cin >> n >> p;
    int sum = 0, k;
    FOR(i, 0, n) {
        cin >> k;
        sum += k;
    }
    cout << sum + min(n - p, p - 1) + n - 1 << endl;
    return 0;
}
