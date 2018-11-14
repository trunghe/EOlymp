/*
 * https://www.e-olymp.com/en/problems/986
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
//#define FORE(i, a, b) \
//    for (int i = (a); i <= (b); i++)
//#define FORD(i, a, b) \
//    for (int i = (a); i >= (b); i--)
#define MAX 102

int countDown[MAX], countUp[MAX];
int maxCount = 1;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//  freopen("error.txt", "w", stderr);
    int n;
    cin >> n;

    FOR(i, 0, n) {
        int num;
        cin >> num;
        countDown[num - 1]++;
        if (maxCount < countDown[num - 1]) {
            maxCount = countDown[num - 1];
        }
        countDown[num]++;
        if (maxCount < countDown[num]) {
            maxCount = countDown[num];
        }
        countUp[num]++;
        countUp[num + 1]++;
        if (maxCount < countUp[num + 1]) {
            maxCount = countUp[num + 1];
        }

    }
    cout << maxCount << endl;

    return 0;
}
