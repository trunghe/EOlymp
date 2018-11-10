/*
https://www.e-olymp.com/en/problems/3747

 Category: Geometry / Math
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)

#define MAX 101
struct Point {
    ll x, y;

    Point() {}

    Point(ll const& _x, ll const& _y) {
        this->x = _x;
        this->y = _y;
    }
};

struct Point points[MAX];
int n;
int maxCount;
ll diffByCy, diffCyAy, diffAyBy;
ll sumSquareAxAy, sumSquareBxBy, sumSquareCxCy;
ll det, detSquared;
ll xcTimesDet, ycTimesDet;
ll prodSquareRadiusDet;

// function to check if 3 points collinear or not
bool collinear(Point p1, Point p2, Point p3) {
    // Calculation the area of
    // triangle. We have skipped
    // multiplication with 0.5
    // to avoid floating point
    // computations
    return p1.x * (p2.y - p3.y) +
            p2.x * (p3.y - p1.y) +
            p3.x * (p1.y - p2.y) == 0;
}

ll sumSquareDist(Point p) {
    ll squareDiffPxXc = p.x * det - xcTimesDet;
    squareDiffPxXc *= squareDiffPxXc;
    ll squareDiffPyYc = p.y * det - ycTimesDet;
    squareDiffPyYc *= squareDiffPyYc;
    return (squareDiffPxXc + squareDiffPyYc);
}

int solve(Point a, Point b, Point c, int i) {

    //cerr << a.x << " " << a.y << endl;
    //cerr << b.x << " " << b.y << endl;
    //cerr << c.x << " " << c.y << endl;

    int count = 2;

    //cerr << (collinear(a, b, c) ? "true" : "false") << endl;

    if (!collinear(a, b, c)) {
        count++;
        diffByCy = b.y - c.y, diffCyAy = c.y - a.y, diffAyBy = a.y - b.y;
        det = (a.x * diffByCy + b.x * diffCyAy + c.x * diffAyBy);
        detSquared = det * det;
        det <<= 1;
//         det *= 2;
        detSquared <<= 2;
//         detSquared *= 4;

        sumSquareAxAy = a.x * a.x + a.y * a.y,
                sumSquareBxBy = b.x * b.x + b.y * b.y,
                sumSquareCxCy = c.x * c.x + c.y * c.y;

        xcTimesDet = (sumSquareAxAy * diffByCy + sumSquareBxBy * diffCyAy +
                         sumSquareCxCy * diffAyBy);
        ycTimesDet = (sumSquareAxAy * (c.x - b.x) + sumSquareBxBy * (a.x - c.x) +
                         sumSquareCxCy * (b.x - a.x));

        //cerr << xcTimesDet << " " << ycTimesDet << endl;
        //cerr << "det = " << det << endl;

        prodSquareRadiusDet = sumSquareDist(a); // (r*d)^2
        //cerr << "detSquared = " << detSquared << endl;
        //cerr << "(r*d)^2 = " << prodSquareRadiusDet << endl;

        for (; i < n; i++) {
            //cerr << "points[" << i << "]:" << points[i].x << " " << points[i].y << endl;
            //cerr << "SSD[i] = " << sumSquareDist(points[i]) << endl;
            if (sumSquareDist(points[i]) == prodSquareRadiusDet) {
                //cerr << points[i].x << " " << points[i].y << endl;
                count++;
            }
        }
    }
    //cerr << "count = " << count << endl << endl;
    return count;
}

void input() {
    FOR (i, 0, n) {
        ll x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;

	while (n > 0) {
        maxCount = 1;
        input();
        if (n > 3) {
            FOR (i, 0, n) {
                FOR (j, i + 1, n) {
                    FOR (k, j + 1, n) {
                        maxCount = max(maxCount,
                                solve(points[i], points[j], points[k], k + 1));
                        // OPTIMIZE HERE!
                    }
                }
            }
            cout << maxCount << endl;
        } else if (n < 3) {
            cout << n << endl;
        } else { // n == 3
            cout << (collinear(points[0], points[1], points[2]) ? 2 : 3) << endl;
        }
        //cerr << "================================================" << endl;
	    cin >> n;
	}

    return 0;
}
