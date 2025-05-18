#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int ArgMax(const vector<double>& v) {
	return distance(v.begin(), max_element(v.begin(), v.end()));
}

void AddEOS(vector<string>& s) {
	for (string& i : s) i = 'E' + i + 'E';
}

void NormalizeP(vector<double>& p) {
	double max = *max_element(p.begin(), p.end());
	for (double& i : p) i /= max;
}

map<array<char, 3>, double> CalcScore(int n, vector<string>& s, vector<double>& p) {
	map<array<char, 3>, double> score;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)s[i].size() - 2; j++) {
			score[{s[i][j], s[i][j + 1], s[i][j + 2]}] += p[i];
		}
	}
	for (char i = 'a'; i <= 'f'; i++) {
		for (char j = 'a'; j <= 'f'; j++) {
			for (char k = 'a'; k <= 'f'; k++) {
				score[{i, j, k}] += score[{i, j, 'E'}] * score[{'E', j, k}];
				score.erase({i, j, 'E'});
				score.erase({'E', j, k});
			}
		}
	}
	return score;
}

map<array<char, 3>, double>::iterator MaxScore(map<array<char, 3>, double>& score) {
	return max_element(score.begin(), score.end(), [](const auto& l, const auto& r) { return l.second < r.second; });
}

vector<pair<array<char, 3>, double>> GetTop(int m, map<array<char, 3>, double>& score) {
	vector<pair<array<char, 3>, double>> top(m);
	for (int i = 0; i < m; i++) {
		auto max = MaxScore(score);
		top[i] = *max;
		score.erase(max);
	}
	return top;
}

void ToInt(int m, const vector<vector<double>>& w, vector<vector<int>>& a) {
    for (int i = 0; i < m; i++) {
        double sum_w = reduce(w[i].begin(), w[i].end());
        vector<pair<double, int>> frac(m);
        int sum_a = 0;
        if (sum_w == 0) {
            // 全て0なら均等に割り振る
            int base = 100 / m;
            int rest = 100 % m;
            for (int j = 0; j < m; j++) a[i][j] = base;
            for (int j = 0; j < rest; j++) a[i][j]++;
            continue;
        }
        for (int j = 0; j < m; j++) {
            double val = w[i][j] / sum_w * 100.0;
            a[i][j] = (int)floor(val);
            frac[j] = {val - a[i][j], j};
            sum_a += a[i][j];
        }
        // 足りない分を小数点以下が大きい順に足す
        int rest = 100 - sum_a;
        sort(frac.rbegin(), frac.rend());
        for (int k = 0; k < rest; k++) {
            a[i][frac[k].second]++;
        }
    }
}

void Solve(int n, int m, int l, vector<string>& s, vector<double>& p, vector<char>& c, vector<vector<int>>& a) {
	AddEOS(s);
	NormalizeP(p);
	map<array<char, 3>, double> score = CalcScore(n, s, p);
	vector<pair<array<char, 3>, double>> top = GetTop(m, score);
	for (int i = 0; i < m; i++) c[i] = top[i].first[1];
	vector<vector<double>> w(m, vector<double>(m, 0.0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (c[j] == top[i].first[0]) w[j][i] += top[i].second;
		}
		for (int j = 0; j < m; j++) {
			if (c[j] == top[i].first[2]) w[i][j] += top[i].second;
		}
	}
	ToInt(m, w, a);
}

int main(void) {
	int n, m, l;
	cin >> n >> m >> l;
	vector<string> s(n);
	vector<double> p(n);
	for (int i = 0; i < n; i++) cin >> s[i] >> p[i];
	vector<char> c(m, 'a');
	vector<vector<int>> a(m, vector<int>(m, 0));

	Solve(n, m, l, s, p, c, a);

	for (int i = 0; i < m; i++) {
		cout << c[i];
		for (int j = 0; j < m; j++) cout << ' ' << a[i][j];
		cout << endl;
	}
	return 0;
}