#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
	char s1, s2, t1, t2;
	cin >> s1 >> s2 >> t1 >> t2;

	int ls, lt;
	if (abs(s2 - s1) == 1 || abs(s2 - s1) == 4) ls = 1;
	else ls = 2;
	if (abs(t2 - t1) == 1 || abs(t2 - t1) == 4) lt = 1;
	else lt = 2;

	if (ls == lt) cout << "Yes" << endl;
	else  cout << "No" << endl;

	return 0;
}