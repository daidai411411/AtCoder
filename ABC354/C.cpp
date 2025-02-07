#include <algorithm>
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
#include <vector>

using namespace std;
using ll = long long;

class Card {
   public:
	int i, A, C;
};

int main() {
	int N;
	cin >> N;
	vector<Card> cards(N);
	for (int i = 0; i < N; i++) {
		cards[i].i = i + 1;
		cin >> cards[i].A >> cards[i].C;
	}

	sort(cards.begin(), cards.end(), [](const Card& ac1, const Card& ac2) { return ac1.A > ac2.A; });

	set<int> remainders;
	int min_C = 1000000001;
	for (int i = 0; i < N; i++) {
		if (cards[i].C < min_C) {
			min_C = cards[i].C;
			remainders.insert(cards[i].i);
		}
	}

	cout << remainders.size() << endl;
	for (int i : remainders) cout << i << " ";
	cout << endl;

	return 0;
}
