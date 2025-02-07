#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#define PARENT(i) ((int)floor(i / 2.0))

using namespace std;

template <typename T, class Comp = less<T>>
void Mergesort(vector<T>& v, Comp comp = less<T>()) {
	if (v.size() != 1) {
		int mid = floor(v.size() / 2.0f);
		vector<T> v_l(v.begin(), v.begin() + mid), v_r(v.begin() + mid, v.end());
		Mergesort(v_l, comp);
		Mergesort(v_r, comp);

		auto itr_l = v_l.begin(), itr_r = v_r.begin();
		for (T& e : v) {
			if (itr_l == v_l.end()) e = *(itr_r++);
			else if (itr_r == v_r.end()) e = *(itr_l++);
			else {
				if (comp(*itr_l, *itr_r)) e = *(itr_l++);
				else e = *(itr_r++);
			}
		}
	}
}

struct Compare {
	bool operator()(int n1, int n2) {
		return n1 > n2;
	}
};

int main() {
	int size;
	cout << "size : " << flush;
	cin >> size;

	vector<int> v(size);
	iota(v.begin(), v.end(), 0);
	random_device seed_gen;
	mt19937 engine(seed_gen());
	shuffle(v.begin(), v.end(), engine);

	vector<int> v1(v);
	sort(v1.begin(), v1.end());

	vector<int> v2(v);
	Mergesort(v2);

	cout << "result: " << ((v1 == v2) ? "equal" : "not equal") << endl;

	return 0;
}
