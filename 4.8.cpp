
#include <iostream>
#include <string>

int main() {

	using namespace std;

	struct Pizze {
		string name;
		float diameter = 0;
		float weight = 0;
	};

	struct Pizze* pizze = new Pizze;

	cout << "Enter pizze'name:";
	getline(cin, pizze->name);
	cout << "Enter pizze'diameter:";
	cin >> pizze->diameter;
	cout << "Enter pizze'weight:";
	cin >> pizze->weight;
	cout << pizze->name << "'weight is " << pizze->weight << " and its diameter is " << pizze->diameter << endl;

	delete pizze;

	return 0;

}