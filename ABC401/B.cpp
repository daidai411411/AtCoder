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
using ull = unsigned long long;

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (string& i : s) cin >> i;

	bool is_logined = false;
	int cnt_error = 0;
	for (string i : s) {
		if (i == "login") is_logined = true;
		else if (i == "logout") is_logined = false;
		else if (i == "private" and !is_logined) cnt_error++;
	}

	cout << cnt_error << endl;
	return 0;
}
