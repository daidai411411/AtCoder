#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#define PARENT(i) ((int)floor(i / 2.0f))

using namespace std;

template <typename T, class Comp = less<T>>
void Heapsort(vector<T>& v, Comp comp = less<T>()) {
	for (int size = v.size(); size >= 2; size--) {
		for (int i = size - 1; i > 0; i--) {
			if (comp(v[PARENT(i)], v[i])) swap(v[PARENT(i)], v[i]);
		}
		swap(v[0], v[size - 1]);
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
	Heapsort(v2);

	cout << "result: " << ((v1 == v2) ? "equal" : "not equal") << endl;

	return 0;
}
