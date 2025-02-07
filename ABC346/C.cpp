#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
	long n;
	long k;
	cin >> n >> k;
	long long total = k * (k + 1) / 2;

	set<long> a;
	for (int i = 0; i < n; i++) {
		long num;
		cin >> num;
		if (num <= k) a.insert(num);
	}
	
	for (long num : a){
		total -= num;
	}

	cout << total << endl;

	return 0;
}
