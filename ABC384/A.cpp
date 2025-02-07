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
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int n;
	char c1, c2;
	string s;
	cin >> n >> c1 >> c2 >> s;

	for (char& c : s) {
		if (c != c1) c = c2;
	}

	cout << s << endl;

	return 0;
}
