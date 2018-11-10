/*
https://www.e-olymp.com/en/problems/3834
 
 Category: Ad Hoc
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    ll n, m, i, res;
    cin >> n >> m >> i;
    while (n > 0) {
        res = (n - 7) * (m - 7) / 2;
        if (!(n & 1) && !(m & 1)) {
            res += i;
        }
        cout << res << endl;
        cin >> n >> m >> i;
    }

    return 0;
}
