
#include <iostream>
#include <vector>


int main() {

	using namespace std;

	struct car {
		string name;
		int year;
	};

	int num;

	cout << "How many cars do you wish to catalog?";
	cin >> num;

	vector<car> Car(num);

	for (int i = 0; i < num; i++) {
		cout << "Car #" << i + 1 << endl;
		cout << "Please enter the make: ";
		cin >> Car[i].name;
		cout << "Please enter the year made: ";
		cin >> Car[i].year;
	}

	cout << "Here is your collection:" << endl;

	for (int i = 0; i < num; i++) {
		cout << Car[i].year << " " << Car[i].name << endl;
	}
	

	return 0;

}
