
#include <iostream>
#include <string>


int main() {

	using namespace std;

	int row,begin = 1;

	cout << "Enter number of rows: ";
	cin >> row;

	while (begin <= row) {

		for (int i = 0; i < row - begin; i++) {
			cout << ".";
		}

		for (int i = 0; i < begin; i++) {
			cout << "*";
		}

		cout << endl;

		begin++;

	}

	return 0;

}
