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

int main(void) {
	double a, b;
	cin >> a >> b;
	if (a + b == 9 || a - b == 9 || a * b == 9 || a / b == 9) cout << "Nine" << endl;
	else cout << "Nein" << endl;
	return 0;
}
