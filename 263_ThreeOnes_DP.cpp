#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    if (n < 3) {
        cout << (1 << n);
    } else {
        int noSeqs[4] = {2, 2, 2, 1};
        FOR(i, 3, n) {
            int temp[4] = {(noSeqs[0] + noSeqs[1]) % 12345,
                           (noSeqs[2] + noSeqs[3]) % 12345,
                           (noSeqs[0] + noSeqs[1]) %12345,
                            noSeqs[2] % 12345};
            FOR(i, 0, 4) {
                noSeqs[i] = temp[i];
            }
        }
        int sum = 0;
        FOR(i, 0, 4) {
            sum = (sum + noSeqs[i]) % 12345;
        }
        cout << sum;
    }
    cout << endl;
    return 0;
}
