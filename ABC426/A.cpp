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
	string x, y;
	cin >> x >> y;
	map<string, int> versions;
	versions["Ocelot"] = 0;
	versions["Serval"] = 1;
	versions["Lynx"] = 2;
	if (versions[x] >= versions[y]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
