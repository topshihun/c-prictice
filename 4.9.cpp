
#include <iostream>
#include <string>

int main() {

	using namespace std;

	struct CandyBar {
		string name;
		float weight;
		int caloria;
	};

	struct CandyBar *snack = new struct CandyBar[3];
	snack[0] = { "Mocha Munch", 2.3 , 350 };
	snack[1] = { "Mocha Munch", 2.3 , 350 };
	snack[2] = { "Mocha Munch", 2.3 , 350 };
	
	cout << "snack'name is " << snack[1].name << endl;
	cout << "snack'weight is " << snack[2].weight << endl;
	cout << "snack'caloria is " << snack[0].caloria << endl;

	delete[] snack;

	return 0;

}