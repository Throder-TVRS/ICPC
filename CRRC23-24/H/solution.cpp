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

void solve_H()
{
    int64_t n, a, k, p;
    cin >> n >> a >> k >> p;

    set<pair<int64_t, int64_t>> values;

    values.insert({ a, 1 });

    for (int64_t i = 2; i <= 5; ++i)
    {
        a = (a * k) % p;

        values.insert({ a, i });
    }

    int64_t mn = values.begin()->first;

    for (int64_t i = 6; i <= n; ++i)
    {
        a = (a * k) % p;

        if (a > mn) {
            values.insert({ a, i });
            values.erase(*(values.begin()));
            mn = values.begin()->first;
        }
    }

    for (const auto& x : values)
        cout << x.first << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve_H();

    return 0;
}
