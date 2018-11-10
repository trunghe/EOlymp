/*
The next number
Given the number n. Output the number n+1.

Input
A non-negative integer n. The number of digits does not exceed 10^6.

Output
The number n+1.

Category: BigNum
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    char digitBeforeNine;
    cin >> digitBeforeNine;
    char digit = 'a';
    int countConsecutiveNines = 0;
    while (true) {
        while (cin >> digit && digit == '9') {
            countConsecutiveNines++;
        }
        if (digit == '9') {// No more digits
            if (digitBeforeNine == '9') {
                cout << "10";
            } else {
                cout << (char) (digitBeforeNine + 1);
            }
            for (int i = 0; i < countConsecutiveNines; ++i) {
                cout << '0';
            }
            break;
        } else if (digit == 'a') {// Only 1 digit
            if (digitBeforeNine == '9') {
                cout << "10";
            } else {
                cout << (char) (digitBeforeNine + 1);
            }
            break;
        } else {
            cout << digitBeforeNine;
            for (int i = 0; i < countConsecutiveNines; ++i) {
                cout << '9';
            }
            digitBeforeNine = digit;
            digit = 'a';
            countConsecutiveNines = 0;
        }
    }
    cout << endl;
    return 0;
}
