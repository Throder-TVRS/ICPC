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
#include <deque>
using namespace std;

void solve_M() {
    int64_t n;
    cin >> n;
    vector<pair<int64_t, pair<int64_t, int64_t>>> data;
    data.resize(n);

    for (int64_t i = 0; i < n; i++) {
        cin >> data[i].second.second;
        data[i].second.second--;
        data[i].second.first = i;
    }

    for (int64_t i = 0; i < n; i++) {
        cin >> data[i].first;
        data[i].first = -data[i].first;
    }

    sort(data.begin(), data.end());

    vector<int64_t> seats;
    seats.resize(n, -1);
    int64_t ret = 0;
    deque<int64_t> left;


    for (int64_t i = 0; i < n; i++)
        if (seats[data[i].second.second] == -1) {
            seats[data[i].second.second] = data[i].second.first;
        }
        else {
            ret += data[i].first;
            left.push_back(data[i].second.first);
        }

    for (int64_t i = 0; i < n; i++)
        if (seats[i] == -1) {
            seats[i] = left.front();
            left.pop_front();
        }

    vector<int64_t> out(n);

    for (int64_t i = 0; i < n; i++)
        out[seats[i]] = i;

    cout << (-ret) << '\n';

    for (int64_t i = 0; i < n; i++)
        cout << out[i] + 1 << ' ';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve_M();

    return 0;
}
