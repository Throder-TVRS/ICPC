#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;

void solve_K()
{
    double a, b, c, d;

    cin >> a >> b >> c >> d;

    if (a >= c && b >= d) {
        cout << "YES" << endl;
        return;
    }

    swap(c, d);

    if (a >= c && b >= d) {
        cout << "YES" << endl;
        return;
    }

    if (c < d)
        swap(c, d);

    double alpha = atan(a / b);
    double beta = 3.14159265 / 2.0 - alpha;

    double v = c * sin(alpha);
    double u = c * sin(beta);
    double x = b - u;
    double z = d / 2;
    double y = z / sin(alpha);

    if (x >= y)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve_K();

    return 0;
}
