/*
 * https://www.e-olymp.com/en/problems/1283
 * Description: Given a positive integer N <= 7489, calculate how many ways
 *              we can combine 1, 5, 10, 25, and 50 to make a sum == N.
 * Category: Dynamic Programming
 * Solution: Let i = N / 5, C = {1/5, 5/5, 10/5, 25/5, 50/5}.
 *          DP formula: DP(i, j) = DP(i-C[j], j) + DP(i, j-1) for i >= C[j]
 *                      DP(i, j) = DP(i, j-1) otherwise
 *          DP(i, j) is the number of ways to combine (j+1) numbers
 *          (from C[0] to C[j]) into a sum == i.
 * Vu Thanh Trung 2018/11/02
 */

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 1500

static ll c[5] = {0, 1, 2, 5, 10};
static ll dp[MAX][5];

void init() {
    for (int j = 0; j < 5; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 0; i < MAX; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j < 5; ++j) {
            if (i < c[j]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i - c[j]][j] + dp[i][j - 1];
            }
        }
    }
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    init();
    int s;
    while (cin >> s) {
        cout << dp[s / 5][4] << endl;
    }

    return 0;
}
/*
Input example #1
11
5
26
Output example #1
4
2
13
 */
/*

 # 1
Accepted	3.54 ms	1,620 KiB

 # 2
Accepted	3.48 ms	1,796 KiB

 # 3
Accepted	4.12 ms	1,648 KiB

 # 4
Accepted	4.10 ms	1,644 KiB

 # 5
Accepted	3.74 ms	1,556 KiB

 # 6
Accepted	3.78 ms	1,752 KiB

 # 7
Accepted	4.07 ms	1,576 KiB

 # 8
Accepted	4.60 ms	1,668 KiB

 # 9
Accepted	6.52 ms	1,624 KiB

 # 10
Accepted	4.81 ms	1,792 KiB

 # 11
Accepted	6.70 ms	1,564 KiB

 # 12
Accepted	6.00 ms	1,632 KiB

 # 13
Accepted	6.84 ms	1,748 KiB

 # 14
Accepted	6.63 ms	1,756 KiB

 # 15
Accepted	9.40 ms	1,800 KiB

 # 16
Accepted	21.71 ms	1,736 KiB
16 (100%)	6.25 ms / 21.71 ms	1,682 KiB / 1,800 KiB
 */
