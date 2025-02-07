#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	int a = 0, b = 0;
	for (int i = 0; i < 9; i++) {
		int s;
		cin >> s;
		a += s;
	}
	for (int i = 0; i < 8; i++) {
		int s;
		cin >> s;
		b += s;
	}

	cout << a - b + 1 << endl;

	return 0;
}
