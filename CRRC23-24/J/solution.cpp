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

void solve_J() {
    int32_t n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n + 2, vector<char>(m + 2, '5'));

    for (int32_t i = 1; i <= n; ++i)
        for (int32_t j = 1; j <= m; ++j)
            cin >> matrix[i][j];

    vector<pair<int32_t, int32_t>> to_right((n + 2) * (m + 2));
    vector<pair<int32_t, int32_t>> to_left((n + 2) * (m + 2));
    vector<pair<int32_t, int32_t>> to_up((n + 2) * (m + 2));
    vector<pair<int32_t, int32_t>> to_down((n + 2) * (m + 2));

    pair<int32_t, int32_t> cur;

    for (int32_t i = 1; i <= n; ++i) {
        cur = { i, 1 };

        for (int32_t j = 1; j <= m; ++j) {
            while (matrix[i][j] == '#') {
                cur = { cur.first, j + 1 };
                j++;
            }

            to_left[i * m + j] = cur;
        }
    }

    for (int32_t i = 1; i <= n; ++i) {
        cur = { i, m };

        for (int32_t j = m; j >= 1; --j) {
            while (matrix[i][j] == '#') {
                cur = { cur.first, j - 1 };
                j--;
            }

            to_right[i * m + j] = cur;
        }
    }

    for (int32_t j = 1; j <= m; ++j) {
        cur = { 1, j };

        for (int32_t i = 1; i <= n; ++i) {
            while (matrix[i][j] == '#') {
                cur = { i + 1, cur.second };
                i++;
            }

            to_up[i * m + j] = cur;
        }
    }

    for (int32_t j = 1; j <= m; ++j) {
        cur = { n, j };

        for (int32_t i = n; i >= 1; --i) {
            while (matrix[i][j] == '#') {
                cur = { i - 1, cur.second };
                i--;
            }

            to_down[i * m + j] = cur;
        }
    }

    string commands;
    cin >> commands;

    pair<int32_t, int32_t> cur_pos = { n, 1 };

    for (const auto& command : commands) {
        int64_t pos = cur_pos.first * m + cur_pos.second;

        switch (command) {
        case 'L':
            cur_pos = to_left[pos];
            break;

        case 'R':
            cur_pos = to_right[pos];
            break;

        case 'U':
            cur_pos = to_up[pos];
            break;

        case 'D':
            cur_pos = to_down[pos];
            break;
        }
    }

    cout << cur_pos.second << " " << n - cur_pos.first + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve_J();

    return 0;
}
