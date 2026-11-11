#include <iostream>
using namespace std;

class LootBag {
public:
	int* ids;
	int n;

	LootBag(int size) { //normal constructor
		n = size;
		
		if (n == 0) {
			ids = nullptr;
		}
		else {
			ids = new int[n];
		}
	}

	LootBag(const LootBag& other) { //copy constructor
		n = other.n;

		if (n == 0) {
			ids = nullptr;
		}
		else {
			ids = new int[n];

			for (int i = 0; i < n; i++) {
				ids[i] = other.ids[i];
			}
		}
	}

	~LootBag() { //destructor
		delete[] ids;
	}
};

int main() {
	LootBag bag(3);

	bag.ids[0] = 101;
	bag.ids[1] = 202;
	bag.ids[2] = 303;

	LootBag clone = bag;

	clone.ids[1] = 999;

	cout << "Original: ";
	for (int i = 0; i < bag.n; i++) {
		cout << bag.ids[i] << " ";
	}

	cout << endl;

	cout << "Clone: ";
	for (int i = 0; i < clone.n; i++) {
		cout << clone.ids[i] << " ";
	}

	cout << endl;

	return 0;
}