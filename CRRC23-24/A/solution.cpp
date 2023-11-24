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

bool check(const vector<vector<char>>& matrix, int64_t i, int64_t j) {
    return matrix[i - 1][j - 1] == '#' && matrix[i][j - 1] == '#' && matrix[i + 1][j - 1] == '#' &&
           matrix[i - 1][j] == '#' && matrix[i][j] == '#' && matrix[i + 1][j] == '#' &&
           matrix[i - 1][j + 1] == '#' && matrix[i][j + 1] == '#' && matrix[i + 1][j + 1] == '#';
}

void solve_A() {
    int64_t n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n + 2, vector<char>(m + 2, '#'));

    for (int64_t i = 1; i <= n; ++i)
        for (int64_t j = 1; j <= m; ++j)
            cin >> matrix[i][j];

    vector<vector<char>> output(n + 2, vector<char>(m + 2, '.'));
    vector<vector<bool>> checked(n + 2, vector<bool>(m + 2, false));

    for (int64_t i = 1; i <= n; ++i) {
        for (int64_t j = 1; j <= m; ++j) {
            if (matrix[i][j] != '#')
                continue;

            if (check(matrix, i, j)) {
                output[i][j] = '#';

                for (int64_t k = -1; k <= 1; ++k)
                    for (int64_t l = -1; l <= 1; ++l)
                        checked[i + k][j + l] = true;
            }
        }
    }

    for (int64_t i = 1; i <= n; ++i)
        for (int64_t j = 1; j <= m; ++j)
            if (matrix[i][j] == '#' && !checked[i][j]) {
                cout << "Impossible" << endl;
                return;
            }

    cout << "Possible" << endl;

    for (int64_t i = 1; i <= n; ++i) {
        for (int64_t j = 1; j <= m; ++j)
            cout << output[i][j];

        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    solve_A();

    return 0;
}