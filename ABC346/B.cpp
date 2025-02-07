#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

const int octave_length = 12;
const char* octave_keys = "wbwbwwbwbwbw";

int main() {
	int w, b;
	cin >> w >> b;

	int count_w, count_b;
	for (int start = 0; start < octave_length; start++){
		count_w = count_b = 0;
		for (int key = 0; key < w + b; key++){
			if (octave_keys[(start + key) % octave_length] == 'w') count_w++;
			else count_b++;
		}

		if (count_w == w && count_b == b){
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}
