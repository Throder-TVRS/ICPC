#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <deque>
using namespace std;

void solve_B() {
    int32_t n, m, k;

    map<int, vector<int32_t>> data_x;
    map<int, vector<int32_t>> data_y;

    cin >> n >> m >> k;

    swap(n, m);

    int32_t a, b;
    for (int32_t l = 0; l < k; ++l) {
        cin >> a >> b;

        data_x[a].push_back(b);
        data_y[b].push_back(a);
    }

    int32_t best_kill = 0;
    pair<int32_t, int32_t> best_cell = { 0, 0 };

    for (auto& q : data_x) {
        auto& cells = q.second;
        sort(cells.begin(), cells.end());

        int32_t kills = 0;
        pair<int32_t, int32_t> cell = { 0, 0 };

        if (cells[0] > 1) {
            kills = cells.size();
            cell = { q.first, 1 };
        }
        else if (cells[cells.size() - 1] < n) {
            kills = cells.size();
            cell = { q.first, n };
        }

        for (size_t i = 1; i < cells.size(); ++i) {
            if (cells[i] - cells[i - 1] <= 1)
                continue;

            size_t t_kills = max(i, cells.size() - i);
            if (t_kills > kills) {
                kills = t_kills;
                cell = { q.first, cells[i - 1] + 1 };
            }
        }

        if (kills > best_kill) {
            best_kill = kills;
            best_cell = cell;
        }
    }


    for (auto& q : data_y) {
        auto& cells = q.second;
        sort(cells.begin(), cells.end());

        int32_t kills = 0;
        pair<int32_t, int32_t> cell = { 0, 0 };

        if (cells[0] > 1) {
            kills = cells.size();
            cell = { 1, q.first };
        }
        else if (cells[cells.size() - 1] < m) {
            kills = cells.size();
            cell = { m, q.first };
        }

        for (size_t i = 1; i < cells.size(); ++i) {
            if (cells[i] - cells[i - 1] <= 1)
                continue;

            size_t t_kills = max(i, cells.size() - i);
            if (t_kills > kills) {
                kills = t_kills;
                cell = { cells[i - 1] + 1, q.first };
            }
        }

        if (kills > best_kill) {
            best_kill = kills;
            best_cell = cell;
        }
    }

    cout << best_kill << '\n';
    cout << best_cell.first << ' ' << best_cell.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    solve_B();

    return 0;
}