#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool C(const char c1, const char c2) {
	char input;
	cout << "? " << c1 << " " << c2 << endl;
	cin >> input;
	return (input == '<');
}

void Mergesort(vector<char>& v) {
	if (v.size() != 1) {
		int mid = floor(v.size() / 2.0f);
		vector<char> v_l(v.begin(), v.begin() + mid), v_r(v.begin() + mid, v.end());
		Mergesort(v_l);
		Mergesort(v_r);

		auto itr_l = v_l.begin(), itr_r = v_r.begin();
		for (char& c : v) {
			if (itr_l == v_l.end()) c = *(itr_r++);
			else if (itr_r == v_r.end()) c = *(itr_l++);
			else {
				if (C(*itr_l, *itr_r)) c = *(itr_l++);
				else c = *(itr_r++);
			}
		}
	}
}

vector<char> SortFiveAlphabetsWithinSevenComparison() {
	vector<char> v;
	char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';

	;											  // 120
	if (C(b, a)) swap(a, b);					  // 60      ab
	if (C(d, c)) swap(c, d);					  // 30      ab cd
	if (C(c, a)) {								  // 15      ab acd
		swap(a, c);								  //
		swap(b, d);								  //
	}											  //
	if (C(c, e)) {								  // 8       ab acd ce
		if (C(e, d)) swap(d, e);				  //   4     ab acde
		if (C(b, d))							  //   2     abd acde
			if (C(b, c)) v = {a, b, c, d, e};	  //     1   abcde
			else v = {a, c, b, d, e};			  //     1   acbde
		else									  //   2     acde db
			if (C(b, e)) v = {a, c, d, b, e};	  //     1   acdbe
			else v = {a, c, d, e, b};			  //     1   acdeb
	} else										  // 7       ab ec acd
		if (C(a, e))							  //   4     ab aecd
			if (C(b, c))						  //     2   abc aecd
				if (C(b, e)) v = {a, b, e, c, d}; //       1 abecd
				else v = {a, e, b, c, d};		  //       1 aebcd
			else								  //     2   aecd cb
				if (C(b, d)) v = {a, e, c, b, d}; //       1 aecbd
				else v = {a, e, c, d, b};		  //       1 aecdb
		else									  //   3     ab eacd
			if (C(b, d))						  //     2   eacd abd
				if (C(b, c)) v = {e, a, b, c, d}; //       1 eabcd
				else v = {e, a, c, b, d};		  //       1 eacbd
			else v = {e, a, c, d, b};			  //     1   eacdb

	return v;
}

int main() {
	int n, q;
	cin >> n >> q;

	vector<char> v(n);
	if (n == 5 && q == 7) {
		v = SortFiveAlphabetsWithinSevenComparison();
	} else {
		iota(v.begin(), v.end(), 'A');
		Mergesort(v);
	}

	cout << "! ";
	for (char c : v) cout << c;
	cout << endl;

	return 0;
}
