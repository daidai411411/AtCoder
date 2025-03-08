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
	multiset<int> ms;
	ms.insert(1);
	ms.insert(4);
	ms.insert(1);
	ms.insert(2);
	for (int i : ms) cout << i << " ";
	cout << endl;
	return 0;
}
