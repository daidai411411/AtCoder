#include <algorithm>
#include <array>
#include <climits>
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

constexpr double EPS = 1e-12;

struct Vec2 {
	double x, y;

	static Vec2 zero(void) { return {0, 0}; }
	Vec2 operator+(const Vec2& t) const { return {this->x + t.x, this->y + t.y}; }
	Vec2 operator-(const Vec2& t) const { return {this->x - t.x, this->y - t.y}; }
	Vec2 operator*(const double& s) const { return {this->x * s, this->y * s}; }
	Vec2 operator/(const double& s) const { return {this->x / s, this->y / s}; }
	double Inner(const Vec2& t) const { return (this->x * t.x + this->y * t.y); }
	double Mag2(void) const { return this->Inner(*this); }
	double Mag(void) const { return sqrt(this->Mag2()); }
	Vec2 Norm(void) const {
		double m = this->Mag();
		if (m < EPS) return {0.0, 0.0};
		return *this / m;
	}
	double Dist(const Vec2& t) const { return (*this - t).Mag(); }

	friend ostream& operator<<(ostream& ost, const Vec2& v) { return (ost << '{' << v.x << ", " << v.y << '}'); }
};

double CalcDist(Vec2 p, Vec2 s, Vec2 d, double l, double r) {
	double denom = d.Mag2();
	if (denom < EPS) {
		// Direction is (almost) zero: the locus is a single point s.
		return s.Dist(p);
	}
	double t = (p - s).Inner(d) / denom;
	if (t < l) return (s + d * l).Dist(p);
	else if (t > r) return (s + d * r).Dist(p);
	else return (s + d * t).Dist(p);
}

double Solve(void) {
	Vec2 ts, tg, as, ag;
	cin >> ts.x >> ts.y >> tg.x >> tg.y >> as.x >> as.y >> ag.x >> ag.y;

	double tt = ts.Dist(tg), at = as.Dist(ag);
	if (tt < at) {
		swap(ts, as);
		swap(tg, ag);
		swap(tt, at);
	}
	Vec2 td = (tg - ts).Norm(), ad = (ag - as).Norm();
	double min1 = CalcDist(Vec2::zero(), ts - as, td - ad, 0, at);
	double min2 = CalcDist(ag, ts, td, at, tt);
	return min(min1, min2);
}

int main(void) {
	int t;
	cin >> t;
	vector<double> ans(t);
	for (int i = 0; i < t; i++) ans[i] = Solve();
	cout << setprecision(16);
	for (int i = 0; i < t; i++) cout << ans[i] << endl;
	return 0;
}
