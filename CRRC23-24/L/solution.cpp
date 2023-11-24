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

vector<pair<int32_t, int32_t>> get_neighbours(pair<int32_t, int32_t> p) {
    int32_t i = p.first;
    int32_t j = p.second;
    if (i % 2 == 1) {
        return {
            { i - 1, j - 1 }, { i - 1, j }, { i, j - 1 }, { i, j + 1 }, { i + 1, j - 1 }, { i + 1, j }
        };
    }
    else {
        return {
            { i - 1, j + 1 }, { i - 1, j }, { i, j - 1 }, { i, j + 1 }, { i + 1, j + 1 }, { i + 1, j }
        };
    }
}

void solve_L() {
    int32_t n, m;

    cin >> n >> m;

    vector<vector<char>> data(n + 2, vector<char>(m + 2, '.'));

    for (int32_t i = 1; i <= n; i++)
        for (int32_t j = 1; j <= m; j++)
            cin >> data[i][j];

    vector<vector<bool>> seen(n + 2, vector<bool>(m + 2, false));
    vector<vector<int32_t>> lens(n + 2, vector<int32_t>(m + 2, 0));

    for (int32_t i = 0; i <= n + 1; i++) {
        seen[i][0] = true;
        seen[i][m + 1] = true;
    }

    for (int32_t j = 0; j <= m + 1; j++) {
        seen[0][j] = true;
        seen[n + 1][j] = true;
    }

    deque<pair<int32_t, int32_t>> queue;

    for (int32_t j = 1; j <= m; j++)
        if (data[1][j] == '#') {
            queue.push_back({ 1, j });
            seen[1][j] = true;
        }

    for (int32_t j = 1; j <= m; j++)
        if (data[1][j] == '.') {
            queue.push_back({ 1, j });
            lens[1][j] = 1;
            seen[1][j] = true;
        }


    while (queue.size()) {
        pair<int32_t, int32_t> current = queue.front();
        queue.pop_front();

        vector<pair<int32_t, int32_t>> neighbours = get_neighbours(current);

        for (pair<int32_t, int32_t>& q : neighbours) {
            if (seen[q.first][q.second])
                continue;

            seen[q.first][q.second] = true;
            if (data[q.first][q.second] == '#') {
                lens[q.first][q.second] = lens[current.first][current.second];
                queue.push_front(q);
            }
            else {
                lens[q.first][q.second] = lens[current.first][current.second] + 1;
                queue.push_back(q);
            }
        }
    }

    int32_t min = INT32_MAX;

    for (int32_t j = 1; j <= m; j++)
        if (min > lens[n][j])
            min = lens[n][j];

    cout << min;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve_L();

    return 0;
}
