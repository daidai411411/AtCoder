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

int main() {
	vector<int> a(5);
	for (int& i : a) cin >> i;
	if (a == vector<int>{2, 1, 3, 4, 5} or a == vector<int>{1, 3, 2, 4, 5} or a == vector<int>{1, 2, 4, 3, 5} or a == vector<int>{1, 2, 3, 5, 4})
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
