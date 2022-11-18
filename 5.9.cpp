
#include <iostream>
#include <string>


int main() {

	using namespace std;

	string a = { 0 };
	int i = 0;

	cout << "Enter words (to stop, type the word done):" << endl;

	for (;a != "done"; i++) {
		cin >> a;
	}
	
	cout << "You entered a total of " << i - 1 << " words";

	return 0;

}
