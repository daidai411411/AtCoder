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
	int n;
	cin >> n;
	map<string, int> answers;
	int max_count = 0;
	for (int i = 0; i < n; i++) {
		string answer;
		cin >> answer;
		for (char& c : answer) c = toupper(c);
		answers[answer]++;
		if (max_count < answers[answer]) max_count = answers[answer];
	}
	cout << max_count << endl;
	return 0;
}
