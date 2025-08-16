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
	string s;
	cin >> s;
	if (s == "red") s = "SSS";
	else if (s == "blue") s = "FFF";
	else if (s == "green") s = "MMM";
	else s = "Unknown";
	cout << s << endl;
	return 0;
}
