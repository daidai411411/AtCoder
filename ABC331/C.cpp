#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct a_t {
	long index = 0, num = 0, sum = 0;
};

struct Cmp {
	bool operator()(a_t a1, a_t a2) {
		return a1.num > a2.num;
	}
};

int main(void) {
	long N;
	cin >> N;

	vector<a_t> A(N);

	for (long i = 0; i < N; i++) {
		A[i].index = i;
		cin >> A[i].num;
	}

	sort(A.begin(), A.end(), Cmp());

	long series = 1;
	for (long i = 1; i < N; i++) {
		if (A[i].num == A[i - 1].num) {
			A[i].sum = A[i - 1].sum;
			series += 1;
		} else {
			A[i].sum = A[i - 1].sum + A[i - 1].num * series;
			series = 1;
		}
	}

	vector<long> B(N);
	for (a_t& a : A) {
		B[a.index] = a.sum;
	}

	for (long b : B) {
		cout << b << " ";
	}
	cout << endl;

	return 0;
}