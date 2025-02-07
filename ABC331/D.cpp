#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int div_ceil(int dividend, int divisor) {
	return (dividend / divisor + ((dividend % divisor == 0) ? 0 : 1));
}

constexpr int mod_up(int dividend, int divisor) {
	return (dividend % divisor + ((dividend % divisor == 0) ? divisor : 0));
}

int main(void) {
	int N, Q;
	cin >> N >> Q;

	vector<string> P(N);
	long long countP = 0;

	for (string& s : P) {
		cin >> s;
		for (char c : s) {
			if (c == 'B') countP += 1;
		}
	}

	vector<int> A(Q), B(Q), C(Q), D(Q);
	vector<int> si(Q), sj(Q);
	vector<int> AmN(Q), BmN(Q), CmN(Q), DmN(Q);
	for (int q = 0; q < Q; q++) {
		cin >> A[q] >> B[q] >> C[q] >> D[q];
		C[q]++;
		D[q]++;
		si[q] = (C[q] / N) - div_ceil(A[q], N);
		sj[q] = (D[q] / N) - div_ceil(B[q], N);
		AmN[q] = mod_up(A[q], N);
		BmN[q] = mod_up(B[q], N);
		CmN[q] = C[q] % N;
		DmN[q] = D[q] % N;
	}

	vector<long long> count(Q, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (P[i][j] != 'B') continue;

			for (int q = 0; q < Q; q++) {
				if (si[q] < 0 && sj[q] < 0) {
					if (AmN[q] <= i && i < CmN[q] && BmN[q] <= j && j < DmN[q]) {
						count[q]++;
					}
				} else if (si[q] < 0) {
				} else if (sj[q] < 0) {
				} else {
					count[q] = si[q] * sj[q] * countP;
				}
			}
			// oxx
			// x x
			// xxx
			if (biN <= i && bjN <= j) count++;
			// xxo
			// x x
			// xxx
			if (biN <= i && j < ejN) count++;
			// xxx
			// x x
			// oxx
			if (i < eiN && bjN <= j) count++;
			// xxx
			// x x
			// xxo
			if (i < eiN && j < ejN) count++;
			// xxx
			// o x
			// xxx
			if (bjN <= j) count += si;
			// xxx
			// x o
			// xxx
			if (j < ejN) count += si;
			// xox
			// x x
			// xxx
			if (biN <= i) count += sj;
			// xxx
			// x x
			// xox
			if (i < eiN) count += sj;
		}
	}

	/*
		for (int q = 0; q < Q; q++) {
			int bi, bj, ei, ej;
			cin >> bi >> bj >> ei >> ej;
			ei++;
			ej++;

			long long si = (ei / N) - div_ceil(bi, N),
					  sj = (ej / N) - div_ceil(bj, N);

			long long count = 0;

			if (si <= 0 || sj <= 0) { // si, sj の少なくとも一方が 0 以下
				for (int i = bi; i < ei; i++) {
					for (int j = bj; j < ej; j++) {
						if (P[i % N][j % N] == 'B') {
							count += 1;
						}
					}
				}
			} else { // si, sj がともに 1 以上
				count = si * sj * countP;

				int biN = mod_up(bi, N), bjN = mod_up(bj, N),
					eiN = ei % N, ejN = ej % N;

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (P[i][j] == 'B') {
							// oxx
							// x x
							// xxx
							if (biN <= i && bjN <= j) count++;
							// xxo
							// x x
							// xxx
							if (biN <= i && j < ejN) count++;
							// xxx
							// x x
							// oxx
							if (i < eiN && bjN <= j) count++;
							// xxx
							// x x
							// xxo
							if (i < eiN && j < ejN) count++;
							// xxx
							// o x
							// xxx
							if (bjN <= j) count += si;
							// xxx
							// x o
							// xxx
							if (j < ejN) count += si;
							// xox
							// x x
							// xxx
							if (biN <= i) count += sj;
							// xxx
							// x x
							// xox
							if (i < eiN) count += sj;
						}
					}
				}
			}

			cout << count << "\n";
		}
	*/
	cout << flush;

	return 0;
}