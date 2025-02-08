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
	vector<int> look_at(n + 1), number_to_person(n + 1), person_to_number(n + 1);
	for (int i = 1; i <= n; i++) cin >> look_at[i];
	for (int i = 1; i <= n; i++) {
		cin >> person_to_number[i];
		number_to_person[person_to_number[i]] = i;
	}
	for (int i = 1; i <= n; i++) cout << person_to_number[look_at[number_to_person[i]]] << ' ';
	cout << endl;
	return 0;
}
