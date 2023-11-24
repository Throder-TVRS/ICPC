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

struct SuffixAutomatonState {
    int64_t len, link;
    map<char, int64_t> next;
};

class SuffixAutomaton {
public:
    vector<SuffixAutomatonState> states;
    int64_t sz, last;

    SuffixAutomaton(const string& s) {
        states.resize(2 * s.size());
        sz = last = 0;
        states[0].len = 0;
        states[0].link = -1;
        ++sz;

        for (const auto& c : s)
            extend(c);
    }

    ~SuffixAutomaton() {}

    void extend(char c) {
        int64_t cur = sz++;
        states[cur].len = states[last].len + 1;
        int64_t p;
        for (p = last; p != -1 && !states[p].next.count(c); p = states[p].link)
            states[p].next[c] = cur;

        if (p == -1)
            states[cur].link = 0;
        else {
            int64_t q = states[p].next[c];
            if (states[p].len + 1 == states[q].len) {
                states[cur].link = q;
            }
            else {
                int64_t clone = sz++;
                states[clone].len = states[p].len + 1;
                states[clone].next = states[q].next;
                states[clone].link = states[q].link;
                for (; p != -1 && states[p].next[c] == q; p = states[p].link)
                    states[p].next[c] = clone;
                states[q].link = states[cur].link = clone;
            }
        }

        last = cur;
    }

    string longest_common_substring(const string& t) {
        int64_t v = 0, l = 0, best = 0, bestpos = 0;

        for (size_t i = 0; i < t.size(); ++i) {
            while (v && !states[v].next.count(t[i])) {
                v = states[v].link;
                l = states[v].len;
            }

            if (states[v].next.count(t[i])) {
                v = states[v].next[t[i]];
                ++l;
            }

            if (l > best)
                best = l, bestpos = i;
        }

        return t.substr(bestpos - best + 1, best);
    }
};

void solve_D() {

    string dna;
    cin >> dna;

    size_t dna_size = dna.size();

    string reverse_complement(dna_size, ' ');

    map<char, char> reverse_map = {
        {'A', 'T'},
        {'T', 'A'},
        {'C', 'G'},
        {'G', 'C'}
    };

    for (size_t i = 0; i < dna.size(); ++i)
        reverse_complement[dna_size - i - 1] = reverse_map[dna[i]];

    SuffixAutomaton automaton(dna);
    auto answer = automaton.longest_common_substring(reverse_complement);

    cout << answer.size() << endl;
    if (answer.size() != 0)
        cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve_D();

    return 0;
}
