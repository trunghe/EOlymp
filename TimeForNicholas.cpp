#include <bits/stdc++.h>

using namespace std;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int hr1, min1, sec1, hr2, min2, sec2;
    char ch;
    cin >> hr1 >> ch >> min1 >> ch >> sec1
        >> hr2 >> ch >> min2 >> ch >> sec2;
    int h = hr2 - hr1, m = min2 - min1, s = sec2 - sec1;
    if (s < 0) {
        s += 60;
        m -= 1;
    }
    if (m < 0) {
        m += 60;
        h -= 1;
    }
    if (h < 0) {
        h += 24;
    }
    cout << (h < 10 ? "0" : "") << h << ch
         << (m < 10 ? "0" : "") << m << ch
         << (s < 10 ? "0" : "") << s << endl;
    return 0;
}
