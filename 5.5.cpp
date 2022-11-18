
#include <iostream>


int main() {

	using namespace std;

	string month[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int num[12] = { 0 };

	for (int i = 0; i < 12; i++) {

		cout << month[i] << ":";
		cin >> num[i];

	}

	for (int i = 0; i < 12; i++) {
		cout << month[i] << ":" << num[i] << endl;
	}

	return 0;

}
