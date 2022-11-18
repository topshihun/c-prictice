
#include <iostream>


int main() {

	using namespace std;

	int sum = 0;

	for (int i = 1; i != 0;) {
		cout << "WARN:Don't enter so large number." << endl;
		cout << "Enter \"0\" will EXIT" << endl;
		cout << "Enter a number casually:";
		cin >> i;
		sum += i;
		cout << "You enter \"" << i << "\" and the sum is \"" << sum << "\"" << endl;
	}
	
	

	return 0;

}
